//
// Created by Дмитрий Сазонов on 2019-08-05.
//

#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <lame-libmp3lame/lame.h>
#include <stdio.h>

#define BUFFER_SIZE 8192

lame_t lame;

JNIEXPORT void JNICALL Java_com_whenwhat_audiorecording_encoding_Mp3Encoder_initEncoder(JNIEnv *env,
        jobject jobj, jint in_num_channels, jint in_samplerate, jint in_brate,  jint in_quality) {
    lame = lame_init();

    lame_set_num_channels(lame, in_num_channels);
    lame_set_in_samplerate(lame, in_samplerate);
    lame_set_brate(lame, in_brate);
    lame_set_mode(lame, 1);
    lame_set_quality(lame, in_quality);

    int res = lame_init_params(lame);
}

JNIEXPORT void JNICALL Java_com_whenwhat_audiorecording_encoding_Mp3Encoder_destroyEncoder(
        JNIEnv *env, jobject jobj) {
    int res = lame_close(lame);
}

JNIEXPORT void JNICALL Java_com_whenwhat_audiorecording_encoding_Mp3Encoder_encodeFile(JNIEnv *env,
        jobject jobj, jstring in_source_path, jstring in_target_path) {
    const char *source_path, *target_path;
    source_path = (*env)->GetStringUTFChars(env, in_source_path, NULL);
    target_path = (*env)->GetStringUTFChars(env, in_target_path, NULL);

    FILE *input_file, *output_file;
    input_file = fopen(source_path, "rb");
    output_file = fopen(target_path, "wb");

    short input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    int nb_read = 0;
    int nb_write = 0;
    int nb_total = 0;

    while (nb_read = fread(input, sizeof(short), BUFFER_SIZE, input_file)) {
        nb_write = lame_encode_buffer(lame, input, input, nb_read, output, BUFFER_SIZE);
        fwrite(output, nb_write, 1, output_file);
        nb_total += nb_write;
    }

    nb_write = lame_encode_flush(lame, output, BUFFER_SIZE);
    fwrite(output, nb_write, 1, output_file);

    fclose(input_file);
    fclose(output_file);
}
