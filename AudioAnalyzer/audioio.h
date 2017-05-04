#ifndef AUDIOIO_H
#define AUDIOIO_H

#include <QObject>
#include "wavefile.h"

class AudioIO: public QObject
{
    Q_OBJECT
public:
    explicit AudioIO(QObject *parent = 0);
    ~AudioIO();

    bool loadFile(const QString& fileName);
    bool play();

private:
    WavFile* m_file;
    WavFile* m_analysisFile;
};

#endif // AUDIOIO_H
