# Jukebox
This is the code and diagram to the Blue Jukebox located in COSI's Progress exhibit. Blue runs on an Arduino Mega and an Adafruit VS1053 Breakout board. This exhibit allows users to select a track number, and the corresponding track is played. To accomplish this, the mega reads in button presses from the button array on the front of the jukebox. The Mega then uses serial communication to begin playback of the track. Relay control was added to control the button latching and record spinning during playback. There is also a reset button that ends playback and resets the VS1053.

This software is designed to work with any Mega and can be costomized to playback any mp3 file.
