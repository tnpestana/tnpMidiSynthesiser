/*
  ==============================================================================

    DistortionEditor.cpp
    Created: 1 May 2018 8:47:46pm
    Author:  tnpes

  ==============================================================================
*/

#include "DistortionEditor.h"

DistortionEditor::DistortionEditor(TnpMidiSynthAudioProcessor& p, AudioProcessorValueTreeState& apvts)
{
	addAndMakeVisible(titleLabel);
	titleLabel.setText("DISTORTION", dontSendNotification);
	titleLabel.setJustificationType(Justification::centred);

	addAndMakeVisible(driveLabel);
	driveLabel.setText("drive", dontSendNotification);
	driveLabel.setJustificationType(Justification::centredBottom);
	addAndMakeVisible(driveSlider);
	driveSlider.setSliderStyle(Slider::RotaryVerticalDrag);
	driveSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	driveAttachment = std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment>
		(new AudioProcessorValueTreeState::SliderAttachment(apvts, "distortionDrive", driveSlider));

	addAndMakeVisible(rangeLabel);
	rangeLabel.setText("range", dontSendNotification);
	rangeLabel.setJustificationType(Justification::centredBottom);
	addAndMakeVisible(rangeSlider);
	rangeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
	rangeSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	rangeAttachment = std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment>
		(new AudioProcessorValueTreeState::SliderAttachment(apvts, "distortionRange", rangeSlider));

	addAndMakeVisible(mixLabel);
	mixLabel.setText("mix", dontSendNotification);
	mixLabel.setJustificationType(Justification::centredBottom);
	addAndMakeVisible(mixSlider);
	mixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
	mixSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	mixAttachment = std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment>
		(new AudioProcessorValueTreeState::SliderAttachment(apvts, "distortionMix", mixSlider));
}

DistortionEditor::~DistortionEditor()
{
}

void DistortionEditor::paint(Graphics& g)
{
	g.fillAll(Colours::olive);
	getLookAndFeel().setColour(Label::backgroundColourId, Colours::olive);

	titleLabel.setColour(Label::backgroundColourId, Colours::darkolivegreen);

	// Color scheme for child components.
	getLookAndFeel().setColour(Slider::ColourIds::thumbColourId, Colours::olivedrab);
	getLookAndFeel().setColour(Slider::ColourIds::trackColourId, Colours::lightgrey);
	getLookAndFeel().setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::lightgrey);
}

void DistortionEditor::resized()
{
	const int sliderWidth = getWidth() / 3;
	juce::Rectangle<int> area(getLocalBounds());

	titleLabel.setBounds(area.removeFromTop(20).reduced(2));

	juce::Rectangle<int> labelArea(area.removeFromTop(15));
	mixLabel.setBounds(labelArea.removeFromLeft(sliderWidth));
	driveLabel.setBounds(labelArea.removeFromLeft(sliderWidth));
	rangeLabel.setBounds(labelArea.removeFromLeft(sliderWidth));

	juce::Rectangle<int> sliderArea(area.removeFromTop(getHeight()));
	mixSlider.setBounds(sliderArea.removeFromLeft(sliderWidth));
	driveSlider.setBounds(sliderArea.removeFromLeft(sliderWidth));
	rangeSlider.setBounds(sliderArea.removeFromLeft(sliderWidth));
}
