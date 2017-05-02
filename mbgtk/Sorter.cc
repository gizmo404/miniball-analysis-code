#include "Sorter.hh"
#include "g_clx.hh"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

Sorter::Sorter() : m_VBox( Gtk::ORIENTATION_VERTICAL ), m_SortButton( "Sort!" ), m_AddButton( "Add" ) {
	
	// Set the title of our window.
	set_title( "MB Coulex Sorter!" );
	
	// Sets the border width of the window.
	set_border_width(10);
	
	// put the box into the main window.
	add( m_VBox );
	
	// Add the TreeView, inside a ScrolledWindow, with the button underneath:
	m_ScrolledWindow.add( m_TreeView );
	
	// Only show the scrollbars when they are necessary:
	m_ScrolledWindow.set_policy( Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC );
	
	m_VBox.pack_start( m_ScrolledWindow);
	m_VBox.pack_start( m_ButtonBox, Gtk::PACK_SHRINK );
	
	m_ButtonBox.pack_start( m_SortButton, Gtk::PACK_SHRINK );
	m_ButtonBox.set_border_width(5);
	m_ButtonBox.set_layout( Gtk::BUTTONBOX_END );
	m_SortButton.signal_clicked().connect( sigc::mem_fun( *this, &Sorter::on_sort_clicked ) );
	
	// Create the Tree model:
	m_refTreeModel = Gtk::ListStore::create( m_Columns );
	m_TreeView.set_model( m_refTreeModel );

	// Fill the TreeView's model
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	row[m_Columns.m_runNo] = 1;

	// Add the TreeView's view columns:
	// This number will be shown with 3 digits and leading zeroes
	m_TreeView.append_column_numeric( "Run No.", m_Columns.m_runNo, "%03d" );
	
	// Show the widgets.
	// They will not really be shown until this Window is shown.
	m_AddButton.show();
	m_SortButton.show();
	m_VBox.show();
	show_all_children();
	
}

Sorter::~Sorter() {}

void Sorter::on_sort_clicked() {
	
	// Get run names
	vector< string > inputfilenames;
	
	// Make chain for g_clx
	TChain *chain = new TChain( "g_clx", "" );
	for( unsigned int i = 0; i < inputfilenames.size(); i++ ) {
		
		chain->Add( inputfilenames[i].c_str() );
		
	}
	
	// Initiate g_clx
	g_clx x( chain );
	x.Loop( "test.root");
	
}

void Sorter::on_add_clicked() {
	
	// Fill the TreeView's model
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	row[m_Columns.m_runNo] = 1;
	
}
