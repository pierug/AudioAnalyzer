#ifndef AUDIOIO_H
#define AUDIOIO_H

#include <QObject>
#include "wavefile.h"
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioOutput>

class AudioIO: public QObject
{
    Q_OBJECT
public:
    explicit AudioIO(QObject *parent = 0);
    ~AudioIO();

    bool loadFile(const QString& fileName);
    bool play();    
    bool play(const QString &fileName);
    WavFile *file() const;

private:
    WavFile* m_file;
    WavFile* m_analysisFile;
    QAudioOutput* m_audioOutput;
    QAudioFormat m_audioFormat;
};

#endif // AUDIOIO_H
