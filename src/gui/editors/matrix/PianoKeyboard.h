/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*- vi:set ts=8 sts=4 sw=4: */

/*
    Rosegarden
    A MIDI and audio sequencer and musical notation editor.
    Copyright 2000-2018 the Rosegarden development team.

    Other copyrights also apply to some parts of this work.  Please
    see the AUTHORS file and individual file headers for details.

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.
*/

#ifndef RG_PIANOKEYBOARD_H
#define RG_PIANOKEYBOARD_H

#include "gui/rulers/PitchRuler.h"

#include <QSize>

#include <vector>


class QWidget;
class QPaintEvent;
class QMouseEvent;
class QEvent;


namespace Rosegarden
{


class PianoKeyboard : public PitchRuler
{
    Q_OBJECT
public:
    PianoKeyboard(QWidget *parent, int keys = 88);

    virtual QSize sizeHint() const;
    virtual QSize minimumSizeHint() const;

    /* 
     * We want to be able to call this from the matrix view
     */
    void drawHoverNote(int evPitch);

    void hideHoverNote();

protected:

    virtual void paintEvent(QPaintEvent*);

    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);

    // compute all key positions and store them
    //
    void computeKeyPos();

    //--------------- Data members ---------------------------------
    QSize m_keySize;
    QSize m_blackKeySize;
    unsigned int m_nbKeys;

    std::vector<unsigned int> m_whiteKeyPos;
    std::vector<unsigned int> m_blackKeyPos;
    std::vector<unsigned int> m_labelKeyPos;
    std::vector<unsigned int> m_allKeyPos;

    bool                      m_mouseDown;
    bool                      m_selecting;

    // highlight element on the keyboard
    QWidget                  *m_hoverHighlight;
    int                       m_lastHoverHighlight;
    int                       m_lastKeyPressed;
};


}

#endif
