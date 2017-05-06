#include "audioio.h"
#include <QObject>
#include "wavefile.h"
#include "utils.h"

AudioIO::AudioIO(QObject *parent) :
    QObject(parent)
{
    m_file=0;
    m_analysisFile=0;
    m_audioOutput=0;

}

AudioIO::~AudioIO()
{
    delete m_file;
    delete m_analysisFile;
}

bool AudioIO::loadFile(const QString &fileName)
{
    bool result = false;
    if(fileName.isEmpty()){
        qWarning() << "String file name is empty.";
        return false;
    }
    m_file = new WavFile(this);
    if (m_file->open(fileName)) {
        result = true;
    } else {
        qWarning() << "Can't open file.";
        return false;
    }
    if (result) {
        m_analysisFile = new WavFile(this);
        m_analysisFile->open(fileName);
    }
    return result;
}

bool AudioIO::play()
{
    m_audioFormat = m_file->fileFormat();
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(m_audioFormat)) {
        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
        return false;
    }

    m_audioOutput = new QAudioOutput(m_audioFormat, this);
    m_audioOutput->start(m_file);
    return true;
}


bool AudioIO::play(const QString &fileName)
{
    if(!loadFile(fileName)){
        return false;
    }
    m_audioFormat = m_file->fileFormat();
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(m_audioFormat)) {
        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
        return false;
    }

    m_audioOutput = new QAudioOutput(m_audioFormat, this);
    m_audioOutput->start(m_file);
    return true;
}

WavFile *AudioIO::file() const
{
    return m_file;
}

