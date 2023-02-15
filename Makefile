USB=arduino-cli board list | grep 'Arduino Micro' | cut -d' ' -f 1

FQBN=arduino:avr:micro

check-board:
	@echo Detecting connected Arduino boards...
	@echo
	@arduino-cli board list

check-core:
	@arduino-cli board list | grep 'Arduino Micro' | rev | cut -d' ' -f 1 | rev

check-usb:
	@echo Detecting USB port of Arduino Micro...
	@echo
	@$(USB)

install-core:
	@echo Installing core dependencies...
	@echo
	@arduino-cli core install arduino:avr

install-libs:
	@arduino-cli lib install HID-Project

install: install-core install-libs
	@echo Installed!

verify-core:
	@arduino-cli core list

upload:
	@echo Compiling...
	@arduino-cli compile --fqbn $(FQBN) firmware
	@echo Uploading...
	@arduino-cli upload -p $$($(USB)) --fqbn $(FQBN) firmware && echo Uploaded!
