# utf_to_binary

This project contains the source materials for a UTF-8 to binary encoding
activity that was inspired by the [ThinkerSmith Traveling Circuits Lesson 1](http://code.org/files/CSEDbinary.pdf)
activity for CSED Week 2013. CoderDojoDC is using this project for the
2014 Silver Spring Maker Faire.

## Activity

The main idea of the activity is to introduce children to binary and how
computers internally represent text. Children are given name tags and
translation cards with the goal of writing their name in binary. The translation
cards are show the UTF-8 encodings of letters and symbols. Most children
will just need the 1 byte letters for their names, but several multi-byte
encodings are shown for the more advanced learners so that they can learn
how non-Latin based languages and other symbols are encoded. Children can
use markers or pencils to fill in their name tags.

## Materials

The nametags are printed on 4"x2" mailing labels arranged on sheets of 8 on Letter sized
paper. These are the common Avery sheets of mailing labels.

The translation cards are intended to be printed on 3.5" x 2" business cards.

## Helper programs

The utf8tobinary directory contains a Qt program that displays the binary
form of a string in a way that can be copy/pasted. It was very helpful
when creating the cards.

Before you can build it, make sure that you have a C++ compiler and QT5. On
Ubuntu, you can get this by running the following at a shell prompt:

    sudo apt-get install g++ qt5-default

To build, change to the utf8tobinary directory and do the following:

    qmake utf8tobinary.pro
    make

The executable will be in the directory. To run it type:

    ./utf8tobinary

## Notes

The original CSED Week 2013 activity differs from this activity in a couple
main ways:

  1. It uses ASCII instead of UTF-8. We wanted to show some children how
     words from other languages could also be encoded.
  2. The bits are flipped. In the CSED Week activity, the binary 0s were
     shaded. The children and adults that tried the activity without instruction
     would shade the binary 1s by default, so we switch the activity to shading
     binary 1s.

## Creating images for Vistaprint

I didn't have much luck trying to export PDFs from QCAD. The best route seemed
to be making the outer dimensions (3.62" x 2.12") box visible and saving the
image as a bitmap. In the bitmap export dialog, specify width 1085, height 635,
pixels per unit 300, margin 0.
