# Lame-MP3-Encoding
Ковертация PCM файла в MP3 с использованием Lame

```kotlin
        val encoder = Mp3Encoder(
            samplerate = 44100,
            bitRate = 128
        )
        encoder.encode(File(pcmPath), File(mp3Path))
        encoder.destroy()
```

Для перекомпиляции нативного когда после правок вызвать task `buldJni`
