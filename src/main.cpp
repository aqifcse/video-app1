/*****************************************************************
* Author   : Syed Towfiqur Rahim ( Aqif )
* Topic    : GLFW and FFMP Basics
* Date     : 18th February, 2020
* Turorial : https://www.youtube.com/watch?v=MEMzo59CPr8
******************************************************************/
#include <stdio.h>
#include <GLFW/glfw3.h> // Adding libraries for glfw 

bool load_frame ( const char* filename, int* width, int* height, unsigned char** data );

int main ( int argc, const char** argv ) {

	GLFWwindow* window; // Create a window

	if ( !glfwInit() ) {   // If the window is not initialized, send an echo
		printf ( "Couldn't init GLFW\n" );
		return 1;
	}

	window = glfwCreateWindow ( 640, 480, "Hello TiCON", NULL, NULL ); // this creates a 640 by 480 windowed mode window, if it fails it will return a NULL value. follow - https://www.glfw.org/docs/latest/window_guide.html

	if( !window ) { // If we can't open up a window, send an echo
		printf ( "Couldn't open window\n" );
		return 1;
	}

	// We need to make the window stay, so we will use runloop

	//--------------runloop--------------------------------------
	int frame_width, frame_height;
	unsigned char* frame_data;
	if ( !load_frame ( "/home/pc/vegeta.mp4", &frame_width, &frame_height, &frame_data )) {
		printf ( "Couldn't load video frame\n" );
		return 1;
	}

	glfwMakeContextCurrent ( window ); // The window that is open, thats the window I am operating right now in this Thread

	GLuint tex_handle;
	glGenTextures ( 1, &tex_handle );
	glBindTexture ( GL_TEXTURE_2D, tex_handle );
	glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexEnvf ( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, frame_width, frame_height, 0, GL_RGB, GL_UNSIGNED_BYTE, frame_data );

	while ( !glfwWindowShouldClose( window ) ) { //As long as the window should not close, do nothing or glfwWaitEvents ()
		//------------------rendering-----------------------------------------
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        // Set up an orthographic projection
		int window_width, window_height;
		glfwGetFramebufferSize ( window, &window_width, &window_height );
		glMatrixMode ( GL_PROJECTION );
		glLoadIdentity ();
		glOrtho ( 0, window_width, 0, window_height, -1, 1 );

		glMatrixMode ( GL_MODELVIEW );

        // Render whatever you want
        glEnable ( GL_TEXTURE_2D );
        glBindTexture ( GL_TEXTURE_2D, tex_handle );
        glBegin ( GL_QUADS );
        	glTexCoord2d ( 0, 0 ); glVertex2i ( 200, 200 );
        	glTexCoord2d ( 1, 0 ); glVertex2i ( 200 + frame_width, 200 );
        	glTexCoord2d ( 1, 1 ); glVertex2i ( 200 + frame_width, 200 + frame_height );
        	glTexCoord2d ( 0, 1 ); glVertex2i ( 200, 200 + frame_height );
        glEnd ();
        glDisable ( GL_TEXTURE_2D );

        glfwSwapBuffers ( window ); // There are two buffers - back buffer and front buffer. The writing goes to back buffer. If there is no swap, the back wont show the new writing. Thats why need to swap back to front.
		//-------------------rendering-----------------------------------------
		glfwWaitEvents(); //Staying in a while loop, waiting for events from the user as long as the window should not close 
	}

	//---------------runloop-------------------------------------

	return 0;

}
