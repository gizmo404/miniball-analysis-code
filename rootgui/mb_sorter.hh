// Very basic ROOT GUI to perform sorting of Miniball data
//
// Liam Gaffney (liam.gaffney@cern.ch) - 02/05/2017

#include <TGTextEntry.h>
#include <TGButton.h>
#include <TGButtonGroup.h>
#include <TGLabel.h>
#include <TGFrame.h>
#include <TApplication.h>
#include <TGListBox.h>
#include <TList.h>

class MBSorter {
	
protected:
	
	// Frames
	TGMainFrame	        *main_frame;		// main frame
	TGHorizontalFrame   *left_frame;		// left frame for run list
	TGVerticalFrame     *vert_frame_0;		// vertical frame for rsync
	TGVerticalFrame     *vert_frame_1;		// vertical frame for MedToRoot
	TGVerticalFrame     *vert_frame_2;		// vertical frame for TreeBuilder
	TGVerticalFrame     *vert_frame_3;		// vertical frame for TreeAna
	
	// Labels
	TGLabel				*lab_run_files;		// label for run file list
	TGLabel				*lab_daq_dir;		// label for daq directory
	TGLabel				*lab_local_dir;		// label for local directory
	
	// Text entries
	TGTextEntry         *text_daq_dir;		// text entry for daq directory
	TGTextEntry         *text_local_dir;	// text entry for local directory
	
	// Action buttons
	TGTextButton        *but_rsync;			// button to do rsync
	TGTextButton        *but_medroot;		// button to do MedToRoot
	TGTextButton        *but_build;			// button to do TreeBuilder
	TGTextButton        *but_ana;			// button to do TreeAna
	
	
public:
	TGListBox           *run_list_box;

	MBSorter();		// constructor
	~MBSorter();	// destructor
	
	ClassDef( MBSorter, 1 )
	
};
