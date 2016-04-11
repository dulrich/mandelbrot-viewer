# mandelbrot viewer

curses mandelbrot explorer based on the code snippet from http://mrl.nyu.edu/~perlin/

currently fails after zooming in more than about 120 levels due to overflows

also included is a glsl fragment shader that renders the set

# setup (ncurses)

* libncurses5

# setup (glsl)

* [glfw](https://github.com/glfw/glfw) (required by glslViewer)
* [glslViewer](https://github.com/patriciogonzalezvivo/glslViewer)
* `glslViewer main.frag`


# license

mandelbrot viewer is copyright (C) 2015  David Ulrich.

For full license details see LICENSE.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
