// Very basic ROOT GUI to perform sorting of Miniball data
//
// Liam Gaffney (liam.gaffney@cern.ch) - 02/05/2017

#include "mb_sorter.hh"

MBSorter::MBSorter() {
	
	///////////////////////
	// Create main frame //
	///////////////////////
	main_frame = new TGMainFrame( gClient->GetRoot(), 700, 400, kMainFrame | kVerticalFrame );
	
	///////////////////////
	// Create sub frames //
	///////////////////////
	
	// Left frame - Run list box
	left_frame = new TGHorizontalFrame( main_frame, 150, 325, kLHintsRight | kLHintsTop );
	left_frame->SetName( "left_frame" );
	
	// Right frame 0 - rsync
	vert_frame_0 = new TGVerticalFrame( main_frame, 500, 90, kLHintsRight | kLHintsTop );
	vert_frame_0->SetName( "vert_frame_0" );
	
	// Right frame 1 - MedToRoot
	vert_frame_1 = new TGVerticalFrame( main_frame, 500, 90, kLHintsRight | kLHintsTop  );
	vert_frame_1->SetName( "vert_frame_1" );
	
	// Right frame 2 - TreeBuilder
	vert_frame_2 = new TGVerticalFrame( main_frame, 500, 90, kLHintsRight | kLHintsTop  );
	vert_frame_2->SetName( "vert_frame_2" );
	
	// Right frame 3 - TreeAna
	vert_frame_3 = new TGVerticalFrame( main_frame, 500, 90, kLHintsRight | kLHintsTop  );
	vert_frame_3->SetName( "vert_frame_3" );
	
	
	///////////////////
	// Create labels //
	///////////////////
	
	// Run files
	lab_run_files = new TGLabel( left_frame, "List of file names" );
	lab_run_files->SetTextJustify( 36 );
	lab_run_files->SetMargins( 0, 0, 0, 0 );
	lab_run_files->SetWrapLength( -1 );
	left_frame->AddFrame( lab_run_files,
						 new TGLayoutHints( kLHintsLeft | kLHintsTop, 2, 2, 2, 2 ) );
	
	// DAQ directory
	lab_daq_dir = new TGLabel( vert_frame_0, "DAQ directory" );
	lab_daq_dir->SetTextJustify( 36 );
	lab_daq_dir->SetMargins( 0, 0, 0, 0 );
	lab_daq_dir->SetWrapLength( -1 );
	lab_daq_dir->Resize( 64, lab_daq_dir->GetDefaultHeight() );
	vert_frame_0->AddFrame( lab_daq_dir,
						   new TGLayoutHints( kLHintsLeft | kLHintsTop, 2, 2, 2, 2 ) );
	
	// Local directory
	lab_local_dir = new TGLabel( vert_frame_0, "Local directory" );
	lab_local_dir->SetTextJustify( 36 );
	lab_local_dir->SetMargins( 0, 0, 0, 0 );
	lab_local_dir->SetWrapLength( -1 );
	lab_local_dir->Resize( 64, lab_local_dir->GetDefaultHeight() );
	vert_frame_0->AddFrame( lab_local_dir,
						   new TGLayoutHints( kLHintsLeft | kLHintsBottom, 2, 2, 2, 2 ) );
	
	
	/////////////////////
	// Create list box //
	/////////////////////
	
	// Run files
	run_list_box = new TGListBox( left_frame, -1, kSunkenFrame );
	run_list_box->SetName( "run_list_box" );
	run_list_box->AddEntry( "Entry 1", 0 );
	run_list_box->Resize( 144, 306 );
	left_frame->AddFrame( run_list_box, new TGLayoutHints( kLHintsLeft | kLHintsTop, 2, 2, 2, 2 ) );
	
	
	/////////////////////////
	// Create text entries //
	/////////////////////////
	
	// DAQ directory
	text_daq_dir = new TGTextEntry( vert_frame_0 );
	text_daq_dir->SetMaxLength( 4096 );
	text_daq_dir->SetAlignment( kTextLeft );
	text_daq_dir->SetText( "/path/to/local/med/files" );
	text_daq_dir->Resize( 264, text_daq_dir->GetDefaultHeight() );
	vert_frame_0->AddFrame( text_daq_dir, new TGLayoutHints( kLHintsLeft | kLHintsTop, 2, 2, 2, 2 ) );
	
	// Local directory
	text_local_dir = new TGTextEntry( vert_frame_0 );
	text_local_dir->SetMaxLength( 4096 );
	text_local_dir->SetAlignment( kTextLeft );
	text_local_dir->SetText( "/path/to/local/med/files" );
	text_local_dir->Resize( 264, text_local_dir->GetDefaultHeight() );
	main_frame->AddFrame( text_local_dir, new TGLayoutHints( kLHintsLeft | kLHintsTop, 2, 2, 2, 2 ) );
	
	
	///////////////////////////
	// Create action buttons //
	///////////////////////////
	
	// rsync
	but_rsync = new TGTextButton( vert_frame_0, "Copy from DAQ", -1, TGTextButton::GetDefaultGC()(),
								 TGTextButton::GetDefaultFontStruct(), kRaisedFrame );
	but_rsync->SetTextJustify( 36 );
	but_rsync->SetMargins( 0, 0, 0, 0 );
	but_rsync->SetWrapLength( -1 );
	but_rsync->Resize( 120, 56 );
	vert_frame_0->AddFrame( but_rsync, new TGLayoutHints( kLHintsRight | kLHintsTop, 2, 2, 2, 2 ) );
	
	// MedToRoot
	but_medroot = new TGTextButton( vert_frame_1, "Convert to ROOT", -1, TGTextButton::GetDefaultGC()(),
								   TGTextButton::GetDefaultFontStruct(), kRaisedFrame );
	but_medroot->SetTextJustify( 36 );
	but_medroot->SetMargins( 0, 0, 0, 0 );
	but_medroot->SetWrapLength( -1 );
	but_medroot->Resize( 120, 56 );
	vert_frame_1->AddFrame( but_medroot, new TGLayoutHints( kLHintsRight | kLHintsTop, 2, 2, 2, 2 ) );
	
	// TreeBuilder
	but_build = new TGTextButton( vert_frame_2, "Build tree", -1, TGTextButton::GetDefaultGC()(),
								 TGTextButton::GetDefaultFontStruct(), kRaisedFrame );
	but_build->SetTextJustify( 36 );
	but_build->SetMargins( 0, 0, 0, 0 );
	but_build->SetWrapLength( -1 );
	but_build->Resize( 120, 56 );
	vert_frame_2->AddFrame( but_build, new TGLayoutHints( kLHintsRight | kLHintsTop, 2, 2, 2, 2 ) );
	
	// TreeAna
	but_ana = new TGTextButton( vert_frame_3, "Make histograms", -1, TGTextButton::GetDefaultGC()(),
							   TGTextButton::GetDefaultFontStruct(), kRaisedFrame );
	but_ana->SetTextJustify( 36 );
	but_ana->SetMargins( 0, 0, 0, 0 );
	but_ana->SetWrapLength( -1 );
	but_ana->Resize( 120, 56 );
	vert_frame_3->AddFrame( but_ana, new TGLayoutHints( kLHintsRight | kLHintsTop, 2, 2, 2, 2 ) );
	
	
	/////////////////////
	// Open the window //
	/////////////////////
	
	// Set a name to the main frame
	main_frame->SetWindowName( "MBSorter" );
	
	// Map all sub windows
	main_frame->MapSubwindows();
	left_frame->MapSubwindows();
	vert_frame_0->MapSubwindows();
	vert_frame_1->MapSubwindows();
	vert_frame_2->MapSubwindows();
	vert_frame_3->MapSubwindows();
	
	// Initialize the layout algorithm via Resize()
	//main_frame->Resize( main_frame->GetDefaultSize() );
	
	// Map windows
	main_frame->MapWindow();
	
}

MBSorter::~MBSorter() {
	
	// Clean up main frame...
	main_frame->Cleanup();
	
}

void mb_sorter() {
	
	// Popup the GUI...
	new MBSorter();
	
}
