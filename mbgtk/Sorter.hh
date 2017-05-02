#ifndef GTKMM_SORTER_HH
#define GTKMM_SORTER_HH

#include <gtkmm.h>
//#include <gtkmm/liststore.h>
//#include <gtkmm/box.h>
//#include <gtkmm/button.h>
//#include <gtkmm/window.h>

class Sorter : public Gtk::Window {
	
public:
	Sorter();
	virtual ~Sorter();
	
protected:
	// Signal handlers:
	void on_sort_clicked();
	
	// Tree model columns:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord {
	public:
		
		ModelColumns()
		{ add(m_runNo); }
		
		Gtk::TreeModelColumn<unsigned int> m_runNo;
		
	};
	
	ModelColumns m_Columns;

	// Child widgets:
	Gtk::Box m_VBox;
	Gtk::ButtonBox m_ButtonBox;
	Gtk::Button m_SortButton;
	
	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::TreeView m_TreeView;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
	
	
};

#endif // GTKMM_SORTER_HH