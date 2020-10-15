$input v_texcoord0, v_color0, v_batchinfo

#include "../../../../third-party/bgfx/src/bgfx_shader.sh"

SAMPLER2DARRAY(s_texColour, 0);

void main()
{
	gl_FragColor = texture2D(s_texColour, v_texcoord0) * v_color0;
}
