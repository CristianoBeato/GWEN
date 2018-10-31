/*
===========================================================================
GWEN

Copyright (c) 2010 Facepunch Studios
Copyright (c) 2017-2018 Cristiano Beato

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

#include "Gwen/Gwen.h"
#include "Gwen/Controls/PropertyTree.h"
#include "Gwen/Skin.h"

namespace Gwen
{
	namespace Controls
	{

		Properties* PropertyTree::Add( const TextObject & text )
		{
			TreeNode* node = new PropertyTreeNode( this );
			node->SetText( text );
			node->Dock( Pos::Top );
			Properties* props = new Properties( node );
			props->Dock( Pos::Top );
			return props;
		}

		Properties* PropertyTree::Find( const TextObject & text )
		{
			Controls::Base::List & children = GetChildNodes();

			for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
			{
				PropertyTreeNode* pChild = gwen_cast<PropertyTreeNode> ( *iter );

				if ( !pChild ) { continue; }

				if ( pChild->GetText() == text )
				{
					Base::List & nodechildren = pChild->GetChildren();

					for ( Base::List::iterator iter = nodechildren.begin(); iter != nodechildren.end(); ++iter )
					{
						Properties* pPropertyChild = gwen_cast<Properties> ( *iter );

						if ( !pPropertyChild ) { continue; }

						return pPropertyChild;
					}
				}
			}

			return NULL;
		}
	}
}