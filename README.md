DS Game Maker Library (dsgmLib)
===============================
dsgmLib is an object-orientated C library for Nintendo DS game development. Although it's designed specifically for [DS Game Maker](https://github.com/DSGameMaker/dsgmApp) (which generates dsgmLib code files), it's ideal for general Nintendo DS homebrew games as well.

In particular dsgmLib is a successor to [PAlib](http://sourceforge.net/projects/pands/) and an alternative to [NightFox’s Lib](http://www.nightfoxandco.com/index.php/main-en/coding/nfl-en/).

### What it does

Nintendo DS games are generally written in C, but C isn't a language which directly supports object-orientated programming. dsgmLib provides an object-orientated layer for game development, allowing you to write clean, modular code whilst avoiding [God objects](http://en.wikipedia.org/wiki/God_object).

DS Game Maker generates dsgmLib code like this:

    void ball_touch(ballObjectInstance *me) {
        me->x += 32;
        me->y += 32;
    }

It's clear that when any instance of `ball` is touched, it is moved down and right by 32 pixels.

Importantly we didn't get the sprite number of our object instance and set the position - this would be ugly, and it's how older versions of DS Game Maker worked:

    DSGM_SetSpriteXY(me->screen, me->spriteNumber, DSGM_GetSpriteX(me->screen, me->spriteNumber) + 32, DSGM_GetSpriteY(me->screen, me->spriteNumber) + 32);

Dealing with sprite numbers directly is clunky; the end user shouldn't have to do this. A key feature (or principle) of dsgmLib is providing an abstraction from the OAM (Object Attribute Memory). You don't have to care about sprite numbers or rotation sets - only object instances (which could have any sprite numbers). We've designed this abstraction to make common tasks such as moving a sprite (object instance) as easy as possible.

dsgmLib is feature rich. It has an object grouping system, loads backgrounds and sprites, scrolls backgrounds, and plays sound effects and music.

### As a PAlib Replacement

PAlib is ridiculously old - it was last updated in 2008 - and bloated (it includes things which DS Game Maker has never used such as Mode 7 3D). PAlib also requires an old or modified version of the devkitARM toolchain. As a result, PAlib is very difficult to maintain and a replacement is long over due.

Read more: [PAlib on the devkitPro wiki](http://devkitpro.org/wiki/PAlib)

devkitARM Installation
-------------

You will need the [devkitARM](http://sourceforge.net/projects/devkitpro/files/devkitARM/) toolchain from the vendor [devkitPro](http://devkitpro.org/). You can read the instructions from the [devkitPro wiki](http://devkitpro.org/wiki/Getting_Started/devkitARM) in full or get going right away as follows.

### Windows
Download and run [devkitProUpdater-1.5.3.exe](http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitProUpdater-1.5.3.exe/download). Only "Minimal System" and "devkitARM" are required; install devkitPPC and devkitPSP only if you want to develop for the Nintendo Wii/Sony PSP respectively. Log out and log in again if there are compilation problems.

### OS X, Linux, etc.
Download [devkitARMupdate.pl](http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitARMupdate.pl/download) to your home directory (`/Users/(username)` on OS X or `/home/(username)` on Ubuntu); it's a Perl script. Open a terminal and run this:

    cd ~
    perl devkitARMupdate.pl
    export DEVKITPRO=~/devkitPro
    export DEVKITARM=~/devkitPro/devkitARM

Great! We're done.

Getting Started
---------------
[Download dsgmLib](https://github.com/DSGameMaker/dsgmLib/archive/master.zip), and extract the archive to your devkitPro directory (for example `C:\devkitPro`), then rename the directory `dsgmLib-master` to `dsgmLib`.

Then, create an environment variable called `DSGMLIB` with the value of the path to `dsgmLib.a`, for example `C:\devkitPro\dsgmLib\dsgmLib`.

Additionally, to make use of dsgmLib's DS to DS multiplayer (NiFi) support you will need dsgmDSWIFI. Download the latest version from [here](https://github.com/DSGameMaker/dsgmDSWiFi/releases). Extract the files to your libnds `lib` directory (for example `C:\devkitPro\libnds\lib\`), click yes when asked if you want to overwrite files.

Now open a terminal in the dsgmLib directory. Run `ls` to (hopefully) print this list of files and directories:

    dsgmLib
    examples
    template
    .gitignore
    LICENSE
    Makefile
    README.md

`cd` to `examples` and run `ls` to list the examples:

    Collision
    CustomFont
    DrawableBackground
    NiFi
    RoomPersistency
    TopDownShooter
    CustomVariables
    Priority
    RotsetEffects
    Unpossible
    Makefile

Let's compile the `Collision` example.

`cd` to `Collision` and run `make`:

    cd Collision
    make

You'll see `Collision.nds` is generated which you can run with an emulator like [NO$GBA](http://problemkaputt.de/gba.htm) (for Windows) or [DeSmuME](http://desmume.org/download/) (for Windows/OS X/Linux).

Additionally, you can compile all of the examples at once by running `make` on the `examples` directory.

Recompiling the Library
---------
If you make changes to the library's source code (dsgmLib directory), you'll need to recompile it by running `make` in the directory. Now recompile any projects that link against the library.

FAQs
---------
###Game works fine in the emulator but when playing on a DS with a flashcard there is just a black screen
DS Game Maker uses `NitroFS`, a method of loading data (sprites, backgrounds, music, etc...)  for homebrew games from inside of the compiled .nds file. Unfortunately, many flashcards are designed soley for running pirated games and do not support this homebrew feature. Either you can make your game without using NitroFS (store files in RAM instead), or you can use the [Homebrew Menu](http://devkitpro.org/wiki/Homebrew_Menu) (which supports NitroFS) on your flashcard.

Getting Help
------------
[There's a forum](http://dsgamemaker.com/dsgmforum/viewforum.php?f=31) specifically for discussing bugs/feature requests, or [create a GitHub issue](https://github.com/DSGameMaker/dsgmLib/issues/new).
