static const uint8_t fs_ocornut_imgui_glsl[242] = {
    0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73,  // FSH............s
    0x5f, 0x74, 0x65, 0x78, 0x00, 0x01, 0x00, 0x00,
    0x01, 0x00, 0xd3, 0x00, 0x00, 0x00, 0x76, 0x61,  // _tex..........va
    0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69,
    0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34,  // rying highp vec4
    0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72,
    0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69,  //  v_color0;.varyi
    0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70,
    0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f,  // ng highp vec2 v_
    0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64,
    0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f,  // texcoord0;.unifo
    0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c,
    0x65, 0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74,  // rm sampler2D s_t
    0x65, 0x78, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64,
    0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29,  // ex;.void main ()
    0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77,
    0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74,  // .{.  lowp vec4 t
    0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b,
    0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61,  // mpvar_1;.  tmpva
    0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x74, 0x65,
    0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20,  // r_1 = texture2D
    0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x2c, 0x20,
    0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f,  // (s_tex, v_texcoo
    0x72, 0x64, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20,
    0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43,  // rd0);.  gl_FragC
    0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x28,
    0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31,  // olor = (tmpvar_1
    0x20, 0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c,
    0x6f, 0x72, 0x30, 0x29, 0x3b, 0x0a, 0x7d, 0x0a,  //  * v_color0);.}.
    0x0a, 0x00,                                      // ..
};
static const uint8_t fs_ocornut_imgui_spv[846] = {
    0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73,  // FSH............s
    0x5f, 0x74, 0x65, 0x78, 0x30, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x2c, 0x03, 0x00, 0x00, 0x03, 0x02,  // _tex0.@...,.....
    0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x08, 0x00,
    0x08, 0x00, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x00,  // #...............
    0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00,  // ................
    0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73,
    0x74, 0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00,  // ..GLSL.std.450..
    0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00,  // ................
    0x08, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00,  // ..........main..
    0x00, 0x00, 0x4d, 0x00, 0x00, 0x00, 0x51, 0x00,
    0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x10, 0x00,  // ..M...Q.........
    0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00,  // ................
    0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00,
    0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61,  // ..............ma
    0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
    0x06, 0x00, 0x22, 0x00, 0x00, 0x00, 0x73, 0x5f,  // in........"...s_
    0x74, 0x65, 0x78, 0x53, 0x61, 0x6d, 0x70, 0x6c,
    0x65, 0x72, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,  // texSampler......
    0x06, 0x00, 0x25, 0x00, 0x00, 0x00, 0x73, 0x5f,
    0x74, 0x65, 0x78, 0x54, 0x65, 0x78, 0x74, 0x75,  // ..%...s_texTextu
    0x72, 0x65, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
    0x05, 0x00, 0x4d, 0x00, 0x00, 0x00, 0x76, 0x5f,  // re........M...v_
    0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x51, 0x00,  // color0........Q.
    0x00, 0x00, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63,
    0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00, 0x05, 0x00,  // ..v_texcoord0...
    0x06, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x62, 0x67,
    0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44,  // ......bgfx_FragD
    0x61, 0x74, 0x61, 0x30, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x22, 0x00,  // ata0..G..."...".
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x21, 0x00,  // ......G..."...!.
    0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x22, 0x00,  // ..P...G...%...".
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x21, 0x00,  // ......G...%...!.
    0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x4d, 0x00, 0x00, 0x00, 0x1e, 0x00,  // ..@...G...M.....
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x51, 0x00, 0x00, 0x00, 0x1e, 0x00,  // ......G...Q.....
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00,
    0x04, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x1e, 0x00,  // ......G.........
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00,
    0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00,  // ..............!.
    0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x1a, 0x00, 0x02, 0x00, 0x06, 0x00,  // ................
    0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x19, 0x00,  // .......... .....
    0x09, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  // ................
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  // ................
    0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0b, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00,  // ................
    0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0d, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00,  // ................
    0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x21, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,  // .. ...!.........
    0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x21, 0x00,
    0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..;...!...".....
    0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x24, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,  // .. ...$.........
    0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x24, 0x00,
    0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..;...$...%.....
    0x00, 0x00, 0x1b, 0x00, 0x03, 0x00, 0x31, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00,  // ......1....... .
    0x04, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00,  // ..L...........;.
    0x04, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x4d, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00,  // ..L...M....... .
    0x04, 0x00, 0x50, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x3b, 0x00,  // ..P...........;.
    0x04, 0x00, 0x50, 0x00, 0x00, 0x00, 0x51, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00,  // ..P...Q....... .
    0x04, 0x00, 0x5b, 0x00, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00,  // ..[...........;.
    0x04, 0x00, 0x5b, 0x00, 0x00, 0x00, 0x5c, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00,  // ..[...........6.
    0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,  // ................
    0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x05, 0x00,
    0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, 0x00,  // ..........=.....
    0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x22, 0x00,
    0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x08, 0x00,  // ..#..."...=.....
    0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x25, 0x00,
    0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00,  // ..&...%...=.....
    0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x4d, 0x00,
    0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0b, 0x00,  // ..N...M...=.....
    0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x51, 0x00,
    0x00, 0x00, 0x56, 0x00, 0x05, 0x00, 0x31, 0x00,  // ..R...Q...V...1.
    0x00, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x26, 0x00,
    0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x57, 0x00,  // ......&...#...W.
    0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x8d, 0x00,
    0x00, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x52, 0x00,  // ..............R.
    0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x0d, 0x00,
    0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x8d, 0x00,  // ................
    0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x3e, 0x00,
    0x03, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x7f, 0x00,  // ..N...>.........
    0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......8.......
};
static const uint8_t
    fs_ocornut_imgui_dx9
        [235] = {
            0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73,  // FSH............s
            0x5f, 0x74, 0x65, 0x78, 0x30, 0x01, 0x00, 0x00,
            0x01, 0x00, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x03,  // _tex0...........
            0xff, 0xff, 0xfe, 0xff, 0x1f, 0x00, 0x43, 0x54,
            0x41, 0x42, 0x1c, 0x00, 0x00, 0x00, 0x4f, 0x00,  // ......CTAB....O.
            0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x01, 0x00,
            0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x91,  // ................
            0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x30, 0x00,
            0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00,  // ..H...0.........
            0x02, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x00,  // ..8.......s_tex.
            0xab, 0xab, 0x04, 0x00, 0x0c, 0x00, 0x01, 0x00,
            0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  // ................
            0x00, 0x00, 0x70, 0x73, 0x5f, 0x33, 0x5f, 0x30,
            0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f,  // ..ps_3_0.Microso
            0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x48,
            0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64,  // ft (R) HLSL Shad
            0x65, 0x72, 0x20, 0x43, 0x6f, 0x6d, 0x70, 0x69,
            0x6c, 0x65, 0x72, 0x20, 0x31, 0x30, 0x2e, 0x31,  // er Compiler 10.1
            0x00, 0xab, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00,
            0x00, 0x80, 0x00, 0x00, 0x0f, 0x90, 0x1f, 0x00,  // ................
            0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x01, 0x00,
            0x03, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00,  // ................
            0x00, 0x90, 0x00, 0x08, 0x0f, 0xa0, 0x42, 0x00,
            0x00, 0x03, 0x00, 0x00, 0x0f, 0x80, 0x01, 0x00,  // ......B.........
            0xe4, 0x90, 0x00, 0x08, 0xe4, 0xa0, 0x05, 0x00,
            0x00, 0x03, 0x00, 0x08, 0x0f, 0x80, 0x00, 0x00,  // ................
            0xe4, 0x80, 0x00, 0x00, 0xe4, 0x90, 0xff, 0xff,
            0x00, 0x00, 0x00,  // ...........
        };
static const uint8_t fs_ocornut_imgui_dx11[402] = {
    0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73,  // FSH............s
    0x5f, 0x74, 0x65, 0x78, 0x30, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x70, 0x01, 0x00, 0x00, 0x44, 0x58,  // _tex0.....p...DX
    0x42, 0x43, 0xbe, 0x78, 0xe7, 0xa5, 0x19, 0x0c,
    0x70, 0xeb, 0x4c, 0xb1, 0xac, 0x1f, 0x16, 0x84,  // BC.x....p.L.....
    0xe9, 0x97, 0x01, 0x00, 0x00, 0x00, 0x70, 0x01,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00,  // ......p.......,.
    0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0xd4, 0x00,
    0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x6c, 0x00,  // ..........ISGNl.
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..........P.....
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,  // ................
    0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,  // ................
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x0f,
    0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..........b.....
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x03,  // ................
    0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53,
    0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x43, 0x4f,  // ..SV_POSITION.CO
    0x4c, 0x4f, 0x52, 0x00, 0x54, 0x45, 0x58, 0x43,
    0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0x4f, 0x53,  // LOR.TEXCOORD..OS
    0x47, 0x4e, 0x2c, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00,  // GN,........... .
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,  // ................
    0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x53, 0x56,
    0x5f, 0x54, 0x41, 0x52, 0x47, 0x45, 0x54, 0x00,  // ......SV_TARGET.
    0xab, 0xab, 0x53, 0x48, 0x44, 0x52, 0x94, 0x00,
    0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x25, 0x00,  // ..SHDR....@...%.
    0x00, 0x00, 0x5a, 0x00, 0x00, 0x03, 0x00, 0x60,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x18,  // ..Z....`......X.
    0x00, 0x04, 0x00, 0x70, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, 0x10,  // ...p......UU..b.
    0x00, 0x03, 0xf2, 0x10, 0x10, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x32, 0x10,  // ..........b...2.
    0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x65, 0x00,
    0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00,  // ......e.... ....
    0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xf2, 0x00,  // ..h.......E.....
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x10,
    0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x46, 0x7e,  // ......F.......F~
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00,  // .......`......8.
    0x00, 0x07, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00,  // ... ......F.....
    0x00, 0x00, 0x46, 0x1e, 0x10, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x00,  // ..F.......>.....
    0x00, 0x00,                                      // ..
};
static const uint8_t fs_ocornut_imgui_mtl[559] = {
    0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x73,  // FSH............s
    0x5f, 0x74, 0x65, 0x78, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0d, 0x02, 0x00, 0x00, 0x23, 0x69,  // _tex..........#i
    0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c,
    0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x73, 0x74,  // nclude <metal_st
    0x64, 0x6c, 0x69, 0x62, 0x3e, 0x0a, 0x23, 0x69,
    0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c,  // dlib>.#include <
    0x73, 0x69, 0x6d, 0x64, 0x2f, 0x73, 0x69, 0x6d,
    0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, 0x75, 0x73,  // simd/simd.h>..us
    0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65,
    0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, 0x65,  // ing namespace me
    0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x0a, 0x73, 0x74,
    0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61,  // tal;..struct xla
    0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e,
    0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, 0x0a, 0x20,  // tMtlMain_out.{.
    0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74,
    0x34, 0x20, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46,  //    float4 bgfx_F
    0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30,
    0x20, 0x5b, 0x5b, 0x63, 0x6f, 0x6c, 0x6f, 0x72,  // ragData0 [[color
    0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d,
    0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63,  // (0)]];.};..struc
    0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74,
    0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e,  // t xlatMtlMain_in
    0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66,
    0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x76, 0x5f,  // .{.    float4 v_
    0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x5b,
    0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f,  // color0 [[user(lo
    0x63, 0x6e, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a,
    0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61,  // cn0)]];.    floa
    0x74, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78,
    0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b,  // t2 v_texcoord0 [
    0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f,
    0x63, 0x6e, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a,  // [user(locn1)]];.
    0x7d, 0x3b, 0x0a, 0x0a, 0x66, 0x72, 0x61, 0x67,
    0x6d, 0x65, 0x6e, 0x74, 0x20, 0x78, 0x6c, 0x61,  // };..fragment xla
    0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e,
    0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, 0x61,  // tMtlMain_out xla
    0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e,
    0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c,  // tMtlMain(xlatMtl
    0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x20,
    0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61,  // Main_in in [[sta
    0x67, 0x65, 0x5f, 0x69, 0x6e, 0x5d, 0x5d, 0x2c,
    0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65,  // ge_in]], texture
    0x32, 0x64, 0x3c, 0x66, 0x6c, 0x6f, 0x61, 0x74,
    0x3e, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x20,  // 2d<float> s_tex
    0x5b, 0x5b, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72,
    0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x2c, 0x20,  // [[texture(0)]],
    0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20,
    0x73, 0x5f, 0x74, 0x65, 0x78, 0x53, 0x61, 0x6d,  // sampler s_texSam
    0x70, 0x6c, 0x65, 0x72, 0x20, 0x5b, 0x5b, 0x73,
    0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x28, 0x30,  // pler [[sampler(0
    0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20,
    0x20, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d,  // )]]).{.    xlatM
    0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f,
    0x75, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d,  // tlMain_out out =
    0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20,
    0x20, 0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66,  //  {};.    out.bgf
    0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61,
    0x74, 0x61, 0x30, 0x20, 0x3d, 0x20, 0x73, 0x5f,  // x_FragData0 = s_
    0x74, 0x65, 0x78, 0x2e, 0x73, 0x61, 0x6d, 0x70,
    0x6c, 0x65, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78,  // tex.sample(s_tex
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x2c,
    0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x74, 0x65,  // Sampler, in.v_te
    0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29,
    0x20, 0x2a, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f,  // xcoord0) * in.v_
    0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a,
    0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75,  // color0;.    retu
    0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, 0x0a,
    0x7d, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00,  // rn out;.}......
};
extern const uint8_t* fs_ocornut_imgui_pssl;
extern const uint32_t fs_ocornut_imgui_pssl_size;
