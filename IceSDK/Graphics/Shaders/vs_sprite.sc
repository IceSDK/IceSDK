$input a_position, a_texcoord0, a_color0, a_batchinfo
$output v_texcoord0, v_color0, v_batchinfo

#include "../../../../third-party/bgfx/src/bgfx_shader.sh"

void main()
{
	gl_Position = mul(u_modelViewProj, vec4(a_position, 1.0, 1.0));
	v_texcoord0 = a_texcoord0;
	v_batchinfo = a_batchinfo;
	v_color0 = a_color0;
}
