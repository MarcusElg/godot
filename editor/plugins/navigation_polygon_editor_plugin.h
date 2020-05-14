/*************************************************************************/
/*  navigation_polygon_editor_plugin.h                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef NAVIGATIONPOLYGONEDITORPLUGIN_H
#define NAVIGATIONPOLYGONEDITORPLUGIN_H

#include "editor/plugins/abstract_polygon_2d_editor.h"
#include "scene/2d/navigation_region_2d.h"

class NavigationPolygonEditor : public AbstractPolygon2DEditor {
	GDCLASS(NavigationPolygonEditor, AbstractPolygon2DEditor);

	NavigationRegion2D *node;

	Ref<NavigationPolygon> _ensure_navpoly() const;

protected:
	virtual Node2D *_get_node() const;
	virtual void _set_node(Node *p_polygon);

	virtual int _get_polygon_count() const;
	virtual Variant _get_polygon(int p_idx) const;
	virtual void _set_polygon(int p_idx, const Variant &p_polygon) const;

	virtual void _action_add_polygon(const Variant &p_polygon);
	virtual void _action_remove_polygon(int p_idx);
	virtual void _action_set_polygon(int p_idx, const Variant &p_previous, const Variant &p_polygon);

	virtual bool _has_resource() const;
	virtual void _create_resource();

public:
	NavigationPolygonEditor(EditorNode *p_editor);
};

class NavigationPolygonEditorPlugin : public AbstractPolygon2DEditorPlugin {
	GDCLASS(NavigationPolygonEditorPlugin, AbstractPolygon2DEditorPlugin);

public:
	NavigationPolygonEditorPlugin(EditorNode *p_node);
};

#endif // NAVIGATIONPOLYGONEDITORPLUGIN_H
