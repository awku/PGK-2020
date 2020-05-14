#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"
#include "Shapes.h"
//// end generated include

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{	
	private:
		bool move_shape,reset;
		BigTr Btr_t, Btr_f;
		MediumTr Mtr;
		SmallTr Str_t, Str_f;
		Square Squa;
		Rhomboid Rhom;
		Shapes* ptr_moving_shape;
		int last_x, last_y; // for mouse moving
	protected:
		// Handlers for MyFrame1 events.
		void panelOnKeyDown( wxKeyEvent& event );
		void panelOnMouseEvents( wxMouseEvent& event );
		void panelOnUpdateUI( wxUpdateUIEvent& event );
		void checkOnButtonClick( wxCommandEvent& event );
		void randomOnButtonClick( wxCommandEvent& event );
		bool if_catch_shape(double , double );
		bool is_in_this_shape(Shapes&,int, double , double );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
		void PaintShapes();

};

#endif // __GUIMyFrame1__
