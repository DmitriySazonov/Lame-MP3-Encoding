LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE     := libmp3lame
LOCAL_SRC_FILES  := lame-libmp3lame/bitstream.c lame-libmp3lame/encoder.c lame-libmp3lame/fft.c lame-libmp3lame/gain_analysis.c lame-libmp3lame/id3tag.c lame-libmp3lame/lame.c lame-libmp3lame/mpglib_interface.c lame-libmp3lame/newmdct.c lame-libmp3lame/presets.c lame-libmp3lame/psymodel.c lame-libmp3lame/quantize.c lame-libmp3lame/quantize_pvt.c lame-libmp3lame/reservoir.c lame-libmp3lame/set_get.c lame-libmp3lame/tables.c lame-libmp3lame/takehiro.c lame-libmp3lame/util.c lame-libmp3lame/vbrquantize.c lame-libmp3lame/VbrTag.c lame-libmp3lame/version.c lame_jni.c
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)