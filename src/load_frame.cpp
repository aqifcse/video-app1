#ifdef __cplusplus 
extern "C" {
#endif

#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <inttypes.h>

#ifdef __cplusplus
}
#endif

#ifdef av_err2str
#undef av_err2str
char av_error[AV_ERROR_MAX_STRING_SIZE] = { 0 };
#define av_err2str(errnum) \
    av_make_error_string(av_error, AV_ERROR_MAX_STRING_SIZE, errnum)
#endif



bool load_frame ( const char* filename, int* width_out, int* height_out, unsigned char** data_out ) {
    
    // Open the file using libavformat
	AVFormatContext* av_format_ctx = avformat_alloc_context();
	
	if ( !av_format_ctx ) {
    
    	printf("Couldn't create AVFormatContext\n");
    	return false;
	
	}

	if ( avformat_open_input( &av_format_ctx, filename, NULL, NULL ) != 0 ) {
	
		printf( "Couldn't open video file\n" );
		return false;
	
	}
    
    // find the first valid video stream inside the file
	int video_stream_index = -1;
	AVCodecParameters* av_codec_params;
	AVCodec* av_codec; 

	for ( int i = 0; i < av_format_ctx -> nb_streams; ++i ) {
	
		av_codec_params = av_format_ctx -> streams [ i ] -> codecpar;
		av_codec = avcodec_find_decoder ( av_codec_params -> codec_id );

		if ( !av_codec) {
	
			continue;
	
		}

		if ( av_codec_params -> codec_type == AVMEDIA_TYPE_VIDEO ) {
	
			video_stream_index = i;
			break;
	
		}

	}

	if ( video_stream_index == -1 ) {
	
		printf ( "Couldn't find valid video stream inside file\n" );
		return false;
	
	}

	// Set up a codec context for the decoder
	AVCodecContext* av_codec_ctx = avcodec_alloc_context3 ( av_codec );

	if ( !av_codec_ctx ) {
	
		printf("Couldn't create AVCodecContext\n");
		return false;
	
	}

	if ( avcodec_parameters_to_context ( av_codec_ctx, av_codec_params ) < 0 ) {
	
		printf("Couldn't initialize AVCodecContext\n");
		return false;
	
	}

	if ( avcodec_open2 ( av_codec_ctx, av_codec, NULL ) < 0 ) {
	
		printf("Couldn't open codec\n");
		return false;
	
	}

	AVFrame* av_frame = av_frame_alloc ();
	
	if ( !av_frame ) {
		
		printf("Couldn't allocate AVFrame\n");
		return false;
	
	}

	AVPacket* av_packet = av_packet_alloc ();
	
	if ( !av_packet ) {
		
		printf("Couldn't allocate AVPacket\n");
		return false;
	
	}

	int response;
	
	while ( av_read_frame ( av_format_ctx, av_packet ) >= 0 ) {
		
		if ( av_packet -> stream_index != video_stream_index ) {
			
			continue;
		
		}
	
		response = avcodec_send_packet ( av_codec_ctx, av_packet );
		
		if ( response < 0 ) {
#ifdef av_err2str            
			printf( "Failed to decode packet: %s\n", av_err2str ( response ) );
#endif
			return false;
		
		}

		response = avcodec_receive_frame ( av_codec_ctx, av_frame );
		
		if ( response == AVERROR ( EAGAIN ) || response == AVERROR_EOF ) {
		
			continue;
		
		} else if ( response < 0 ) {
#ifdef av_err2str		    
		    printf( "Failed to decode packet: %s\n", av_err2str ( response ) );	
#endif	  
			return false;
		
		}

		av_packet_unref ( av_packet );
		break;

	}

	unsigned char* data = new unsigned char [ av_frame -> width * av_frame -> height * 3 ];
	
	for ( int x = 0; x < av_frame -> width; ++x ) {
		for ( int y = 0; y < av_frame -> height; ++y ) {
			
			data [ y * av_frame -> width * 3 + x * 3     ] = av_frame -> data [ 0 ][ y * av_frame -> linesize [ 0 ] + x ];
		    data [ y * av_frame -> width * 3 + x * 3 + 1 ] = av_frame -> data [ 0 ][ y * av_frame -> linesize [ 0 ] + x ];
		    data [ y * av_frame -> width * 3 + x * 3 + 2 ] = av_frame -> data [ 0 ][ y * av_frame -> linesize [ 0 ] + x ]; 
 
		}
	}

	*width_out = av_frame -> width;
	*height_out = av_frame -> height;
	*data_out = data;

	avformat_close_input ( &av_format_ctx );
	avformat_free_context ( av_format_ctx );
	av_frame_free ( &av_frame );
	av_packet_free ( &av_packet );
	avcodec_free_context ( &av_codec_ctx );

	return true;

}