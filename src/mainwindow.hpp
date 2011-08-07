/**
 * @file   mainwindow.hpp
 * @brief  Interface definition for callback functions implemented by the main
 *         window.
 *
 * Copyright (C) 2010-2011 Adam Nielsen <malvineous@shikadi.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include <wx/frame.h>

/// Base class for main window.
class IMainWindow: public wxFrame
{
	public:
		IMainWindow(wxWindow *parent, wxWindowID winid, const wxString& title,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE,
			const wxString& name = wxFrameNameStr);

		/// Set the text in the status bar.
		virtual void setStatusText(const wxString& text)
			throw () = 0;

};

#endif // _MAINWINDOW_HPP_