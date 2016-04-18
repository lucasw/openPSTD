//////////////////////////////////////////////////////////////////////////
//                                                                      //
// This file is part of openPSTD.                                       //
//                                                                      //
// openPSTD is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU General Public License as published by //
// the Free Software Foundation, either version 3 of the License, or    //
// (at your option) any later version.                                  //
//                                                                      //
// openPSTD is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of       //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        //
// GNU General Public License for more details.                         //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with openPSTD.  If not, see <http://www.gnu.org/licenses/>.    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#version 330

uniform float vmin;
uniform float vmax;

in vec2 v_texcoord;

uniform sampler2D values;
uniform sampler1D colormap;

void main()
{
    float value = texture2D(values, v_texcoord).r;

    /*if(value < vmin)
    {
        value = vmin;
    }
    else if(value > vmax)
    {
        value = vmax;
    }

    value = (value-vmin)/(vmax-vmin);*/
    //gl_FragColor = texture2D(values, v_texcoord);
    //gl_FragColor = texture2D(values, vec2(0.5,0.5));
    gl_FragColor = vec4(value, v_texcoord.x, v_texcoord.y, 1);
    //gl_FragColor = texture(colormap, value);
    //gl_FragColor = texture(colormap, 0.5);
}