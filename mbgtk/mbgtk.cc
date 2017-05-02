// Make a basic GUI to select filenames and options for Miniball sort code
// Liam Gaffney (liam.gaffney@cern.ch) 01/05/2017

#include "Sorter.hh"

#include <gtkmm/application.h>

int main (int argc, char *argv[]) {
	
	auto app = Gtk::Application::create( argc, argv, "org.gtkmm.example" );
	
	Sorter sorter;
	
	//Shows the window and returns when it is closed.
	return app->run( sorter );
	
}