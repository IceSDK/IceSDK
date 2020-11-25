static const uint8_t fs_imgui_color_glsl[93] = {
    0x46, 0x53, 0x48, 0x06, 0xa4, 0x8b, 0xef, 0x49,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00,  // FSH....I......J.
    0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e,
    0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20,  // ..varying highp
    0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63,
    0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76,  // vec4 v_color0;.v
    0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e,
    0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20,  // oid main ().{.
    0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43,
    0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x76,  // gl_FragColor = v
    0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b,
    0x0a, 0x7d, 0x0a, 0x0a, 0x00,  // _color0;.}...
};
static const uint8_t fs_imgui_color_spv[406] = {
    0x46, 0x53, 0x48, 0x06, 0xa4, 0x8b, 0xef, 0x49,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,  // FSH....I........
    0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00,
    0x01, 0x00, 0x08, 0x00, 0x08, 0x00, 0x2b, 0x00,  // ....#.........+.
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00,
    0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00,  // ................
    0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c,
    0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34,  // ......GLSL.std.4
    0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,  // 50..............
    0x00, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61,  // ..............ma
    0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00,
    0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x10, 0x00,  // in....!...*.....
    0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00,  // ................
    0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00,
    0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61,  // ..............ma
    0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
    0x05, 0x00, 0x21, 0x00, 0x00, 0x00, 0x76, 0x5f,  // in........!...v_
    0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x2a, 0x00,  // color0........*.
    0x00, 0x00, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46,
    0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30,  // ..bgfx_FragData0
    0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x21, 0x00,
    0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..G...!.........
    0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x2a, 0x00,
    0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..G...*.........
    0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x03, 0x00,  // ..........!.....
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x16, 0x00,
    0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0x20, 0x00,  // .............. .
    0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00,  // ................
    0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00,  // .. ... .........
    0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x20, 0x00,
    0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x01, 0x00,  // ..;... ...!.....
    0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x29, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00,  // .. ...).........
    0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x29, 0x00,
    0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x03, 0x00,  // ..;...)...*.....
    0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..6.............
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00,
    0x02, 0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00,  // ..............=.
    0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x22, 0x00,
    0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x3e, 0x00,  // ......"...!...>.
    0x03, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x22, 0x00,
    0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00,  // ..*...".......8.
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,              // ......
};
static const uint8_t fs_imgui_color_dx9[135] = {
    0x46, 0x53, 0x48, 0x06, 0xa4, 0x8b, 0xef, 0x49,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x00,  // FSH....I......t.
    0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0xff,
    0x14, 0x00, 0x43, 0x54, 0x41, 0x42, 0x1c, 0x00,  // ..........CTAB..
    0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x03,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..#.............
    0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x1c, 0x00,
    0x00, 0x00, 0x70, 0x73, 0x5f, 0x33, 0x5f, 0x30,  // ..........ps_3_0
    0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f,
    0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x48,  // .Microsoft (R) H
    0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64,
    0x65, 0x72, 0x20, 0x43, 0x6f, 0x6d, 0x70, 0x69,  // LSL Shader Compi
    0x6c, 0x65, 0x72, 0x20, 0x31, 0x30, 0x2e, 0x31,
    0x00, 0xab, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00,  // ler 10.1........
    0x00, 0x80, 0x00, 0x00, 0x0f, 0x90, 0x01, 0x00,
    0x00, 0x02, 0x00, 0x08, 0x0f, 0x80, 0x00, 0x00,  // ................
    0xe4, 0x90, 0xff, 0xff, 0x00, 0x00, 0x00,        // .......
};
static const uint8_t fs_imgui_color_dx11[266] = {
    0x46, 0x53, 0x48, 0x06, 0xa4, 0x8b, 0xef, 0x49, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xf4, 0x00,  // FSH....I........
    0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0xa6, 0x7f, 0x08, 0xe2,
    0x95, 0xbd, 0x5f, 0xa3, 0x3f, 0x5b,  // ..DXBC......_.?[
    0x58, 0x8e, 0x54, 0x0f, 0x89, 0x67, 0x01, 0x00, 0x00, 0x00,
    0xf4, 0x00, 0x00, 0x00, 0x03, 0x00,  // X.T..g..........
    0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0xb4, 0x00, 0x00, 0x00, 0x49, 0x53,  // ..,...........IS
    0x47, 0x4e, 0x4c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x38, 0x00,  // GNL...........8.
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00,  // ................
    0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......D.........
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x0f, 0x0f, 0x00, 0x00, 0x53, 0x56,  // ..............SV
    0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00,
    0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x00,  // _POSITION.COLOR.
    0xab, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x2c, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x08, 0x00,  // ..OSGN,.........
    0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x00,  // .. .............
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
    0x53, 0x56, 0x5f, 0x54, 0x41, 0x52,  // ..........SV_TAR
    0x47, 0x45, 0x54, 0x00, 0xab, 0xab, 0x53, 0x48, 0x44, 0x52,
    0x38, 0x00, 0x00, 0x00, 0x40, 0x00,  // GET...SHDR8...@.
    0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03,
    0xf2, 0x10, 0x10, 0x00, 0x01, 0x00,  // ......b.........
    0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x36, 0x00,  // ..e.... ......6.
    0x00, 0x05, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x46, 0x1e, 0x10, 0x00, 0x01, 0x00,  // ... ......F.....
    0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,  // ..>.......
};
static const uint8_t fs_imgui_color_mtl[386] = {
    0x46, 0x53, 0x48, 0x06, 0xa4, 0x8b, 0xef, 0x49,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x01,  // FSH....I......l.
    0x00, 0x00, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75,
    0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61,  // ..#include <meta
    0x6c, 0x5f, 0x73, 0x74, 0x64, 0x6c, 0x69, 0x62,
    0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75,  // l_stdlib>.#inclu
    0x64, 0x65, 0x20, 0x3c, 0x73, 0x69, 0x6d, 0x64,
    0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e,  // de <simd/simd.h>
    0x0a, 0x0a, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20,
    0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63,  // ..using namespac
    0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b,
    0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74,  // e metal;..struct
    0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c,
    0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74,  //  xlatMtlMain_out
    0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66,
    0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x62, 0x67,  // .{.    float4 bg
    0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44,
    0x61, 0x74, 0x61, 0x30, 0x20, 0x5b, 0x5b, 0x63,  // fx_FragData0 [[c
    0x6f, 0x6c, 0x6f, 0x72, 0x28, 0x30, 0x29, 0x5d,
    0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73,  // olor(0)]];.};..s
    0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c,
    0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69,  // truct xlatMtlMai
    0x6e, 0x5f, 0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20,
    0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74,  // n_in.{.    float
    0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f,
    0x72, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65,  // 4 v_color0 [[use
    0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x30, 0x29,
    0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a,  // r(locn0)]];.};..
    0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74,
    0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c,  // fragment xlatMtl
    0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74,
    0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c,  // Main_out xlatMtl
    0x4d, 0x61, 0x69, 0x6e, 0x28, 0x78, 0x6c, 0x61,
    0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e,  // Main(xlatMtlMain
    0x5f, 0x69, 0x6e, 0x20, 0x69, 0x6e, 0x20, 0x5b,
    0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69,  // _in in [[stage_i
    0x6e, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20,
    0x20, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d,  // n]]).{.    xlatM
    0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f,
    0x75, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d,  // tlMain_out out =
    0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20,
    0x20, 0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66,  //  {};.    out.bgf
    0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61,
    0x74, 0x61, 0x30, 0x20, 0x3d, 0x20, 0x69, 0x6e,  // x_FragData0 = in
    0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72,
    0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72,  // .v_color0;.    r
    0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75,
    0x74, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00, 0x00,  // eturn out;.}....
    0x00, 0x00,                                      // ..
};
extern const uint8_t* fs_imgui_color_pssl;
extern const uint32_t fs_imgui_color_pssl_size;
