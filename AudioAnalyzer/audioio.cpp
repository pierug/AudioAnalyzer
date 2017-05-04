#include "audioio.h"
#include <QObject>
#include "wavefile.h"

AudioIO::AudioIO(QObject *parent) :
    QObject(parent)
{

}

AudioIO::~AudioIO()
{
    delete m_file;
    delete m_analysisFile;
}

bool AudioIO::loadFile(const QString &fileName)
{
    //reset();
    bool result = false;
    //Q_ASSERT(!m_generateTone);
    //Q_ASSERT(!m_file);
    if(fileName.isEmpty())
        return false;
    m_file = new WavFile(this);
    if (m_file->open(fileName)) {
        result = true;
        /*if (isPCMS16LE(m_file->fileFormat())) {
            result = initialize();
        } else {
            emit errorMessage(tr("Audio format not supported"),
                              formatToString(m_file->fileFormat()));
        }*/
    } else {
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
    return true;
}
