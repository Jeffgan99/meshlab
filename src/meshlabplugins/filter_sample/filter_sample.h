/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

/****************************************************************************
History
$Log: sampleplugins.h,v $

Revision 1,3 2020/05/20
Reorganization of the filter, comments in doxygen format

Revision 1.2  2006/11/29 00:59:21  cignoni
Cleaned plugins interface; changed useless help class into a plain string

Revision 1.1  2006/09/25 09:24:39  e_cerisoli
add sampleplugins

****************************************************************************/

#ifndef FILTERSAMPLE_PLUGIN_H
#define FILTERSAMPLE_PLUGIN_H

#include <common/interfaces/filter_plugin_interface.h>

class FilterSamplePlugin : public QObject, public FilterPluginInterface
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_INTERFACE_IID)
	Q_INTERFACES(FilterPluginInterface)

public:
	enum { FP_MOVE_VERTEX  } ;

	FilterSamplePlugin();

	QString pluginName() const;

	QString filterName(FilterIDType filter) const;
	QString filterInfo(FilterIDType filter) const;
	FilterClass getClass(const QAction* a) const;
	FILTER_ARITY filterArity(const QAction*) const;
	int getPreConditions(const QAction *) const;
	int postCondition(const QAction* ) const;
	void initParameterList(const QAction*, MeshModel &/*m*/, RichParameterList & /*parent*/);
	bool applyFilter(const QAction* action, MeshDocument &md, const RichParameterList & /*parent*/, vcg::CallBackPos * cb);

private:
	bool vertexDisplacement(
			MeshDocument &md,
			vcg::CallBackPos *cb,
			bool updateNormals,
			float max_displacement);
};

#endif
