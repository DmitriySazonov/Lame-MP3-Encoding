package com.whenwhat.audiorecording

import java.io.File

class Mp3Encoder(
    val samplerate: Int,
    val bitRate: Int,
    val channels: Int = 1,
    val quality: Int = DEFAULT_QUALITY
) {

    companion object {
        const val BETTER_QUALITY = 0
        const val DEFAULT_QUALITY = 2
        const val WORST_QUALITY = 9

        init {
            System.loadLibrary("mp3lame")
        }
    }

    init {

        initEncoder(channels, samplerate, bitRate, quality)
    }

    fun encode(sourceFile: File, destinationFile: File) {
        encodeFile(sourceFile.absolutePath, destinationFile.absolutePath)
    }

    fun destroy() {
        destroyEncoder()
    }

    private external fun initEncoder(channels: Int, samplerate: Int, bitRate: Int, quality: Int)

    private external fun destroyEncoder()

    private external fun encodeFile(sourceFile: String, destinationFile: String)
}