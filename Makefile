all: update flash clean
flash: build flash-left flash-right

update: clean-link
	@echo "\x1B[34m日\x1B[0mUpdating QMK"
	@git submodule update --init --recursive

clean-link:
	@echo "\x1B[34m日\x1B[0mCleaning old symlink"
	@rm -rf qmk_firmware/keyboards/ferris/keymaps/diegolhambi

link: clean-link
	@echo "\x1B[34m日\x1B[0mCreating new symlink"
	@ln -s -r src qmk_firmware/keyboards/ferris/keymaps/diegolhambi

clean: clean-link
	@echo "\x1B[34m日\x1B[0mCleaning builds file"
	@cd qmk_firmware; qmk clean -a

lint: link
	@cd qmk_firmware; qmk lint -kb ferris/sweep -km diegolhambi --strict

build: link lint
	@cd qmk_firmware; qmk compile -kb ferris/sweep -km diegolhambi

flash-left: link lint
	@cd qmk_firmware; qmk flash -kb ferris/sweep -km diegolhambi -bl avrdude-split-left

flash-right: link lint
	@cd qmk_firmware; qmk flash -kb ferris/sweep -km diegolhambi -bl avrdude-split-right