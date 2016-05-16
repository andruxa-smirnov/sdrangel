#ifndef INCLUDE_PLUGINAPI_H
#define INCLUDE_PLUGINAPI_H

#include <QObject>
#include "util/export.h"
#include "dsp/dspdeviceengine.h"

class QString;

class PluginManager;
class PluginInterface;
class SampleSource;
class SampleSink;
class DSPEngine;
class AudioFifo;
class MessageQueue;
class MainWindow;
class ChannelMarker;
class ThreadedSampleSink;
class GLSpectrum;
class PluginGUI;

class SDRANGEL_API PluginAPI : public QObject {
	Q_OBJECT

public:
	// MainWindow access
	MessageQueue* getMainWindowMessageQueue();
	void setInputGUI(QWidget* inputGUI, const QString& sourceDisplayName);

	// Channel stuff
	void registerChannel(const QString& channelName, PluginInterface* plugin);
	void registerChannelInstance(const QString& channelName, PluginGUI* pluginGUI);
	void addChannelRollup(QWidget* pluginGUI);
	void removeChannelInstance(PluginGUI* pluginGUI);

	void addChannelMarker(ChannelMarker* channelMarker);
	void removeChannelMarker(ChannelMarker* channelMarker);

	// Sample Source stuff
	void registerSampleSource(const QString& sourceName, PluginInterface* plugin);

	// Device engine stuff
//    void addSink(SampleSink* sink);       //!< Add a sample sink to device engine
//    void removeSink(SampleSink* sink);    //!< Remove a sample sink from device engine
	void addThreadedSink(ThreadedSampleSink* sink);     //!< Add a sample sink that will run on its own thread to device engine
    void removeThreadedSink(ThreadedSampleSink* sink);  //!< Remove a sample sink that runs on its own thread from device engine
//	void setSource(SampleSource* source); //!< Set device engine sample source type
//    bool initAcquisition();               //!< Initialize device engine acquisition sequence
//    bool startAcquisition();              //!< Start device engine acquisition sequence
//    void stopAcquistion();                //!< Stop device engine acquisition sequence
//    DSPDeviceEngine::State state() const; //!< device engine state
//    QString errorMessage();               //!< Return the current device engine error message
//    uint getDeviceUID() const;            //!< Return the current device engine unique ID
//    MessageQueue *getDeviceInputMessageQueue();
//    MessageQueue *getDeviceOutputMessageQueue();
//    void configureCorrections(bool dcOffsetCorrection, bool iqImbalanceCorrection); //!< Configure current device engine DSP corrections

//    GLSpectrum *getSpectrum();

	// R/O access to main window
	const MainWindow* getMainWindow() const { return m_mainWindow; }

protected:
	PluginManager* m_pluginManager;
	MainWindow* m_mainWindow;

	PluginAPI(PluginManager* pluginManager, MainWindow* mainWindow);
	~PluginAPI();

	friend class PluginManager;
};

#endif // INCLUDE_PLUGINAPI_H
