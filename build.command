#!/bin/sh

# Config
name=fence
cart_conf=nrom_128_horz.cfg
include=include
meta=meta
src=source
cc_out=asm
cc_flags=-Oi
platform=nes
ca_out=build
ld_out=bin

# Compile
echo Compiling to assembly...
cc65 $cc_flags -I $include -I $meta -o $cc_out/$name.s $src/$name.c --add-source
cc65 $cc_flags -I $include -I $meta -o $cc_out/nesdev.s $src/nesdev.c --add-source

# Compile to Object
echo Compiling to binary...
ca65 -o $ca_out/$name.o $cc_out/$name.s        # Main game file
ca65 -o $ca_out/nesdev.o $cc_out/nesdev.s      # My own nes lib
ca65 -o $ca_out/neslib.o $cc_out/neslib/crt0.s # Shiru's Neslib

# Link
echo Linking...
ld65 -C $cart_conf -o $ld_out/$name.nes $ca_out/*.o $ca_out/nes.lib

echo Done!
