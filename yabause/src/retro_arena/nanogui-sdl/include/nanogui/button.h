/*
    nanogui/button.h -- [Normal/Toggle/Radio/Popup] Button widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/** \file */

#pragma once

#include <nanogui/widget.h>

NAMESPACE_BEGIN(nanogui)
/**
 * \class Button button.h nanogui/button.h
 *
 * \brief [Normal/Toggle/Radio/Popup] Button widget.
 */
class NANOGUI_EXPORT Button : public Widget {
public:
    /// Flags to specify the button behavior (can be combined with binary OR)
    enum Flags {
        NormalButton = (1 << 0), // 1
        RadioButton  = (1 << 1), // 2
        ToggleButton = (1 << 2), // 4
        PopupButton  = (1 << 3)  // 8
    };

    /// The available icon positions.
    enum class IconPosition {
        Left,
        LeftCentered,
        RightCentered,
        Right
    };

    Button(Widget *parent, const std::string &caption = "Untitled", int icon = 0);

    const std::string &caption() const { return mCaption; }
    void setCaption(const std::string &caption) { mCaption = caption; }

    const Color &backgroundColor() const { return mBackgroundColor; }
    void setBackgroundColor(const Color &backgroundColor) { mBackgroundColor = backgroundColor; }

    const Color &textColor() const { return mTextColor; }
    void setTextColor(const Color &textColor) { mTextColor = textColor; }

    int icon() const { return mIcon; }
    void setIcon(int icon) { mIcon = icon; }

    int flags() const { return mFlags; }
    void setFlags(int buttonFlags) { mFlags = buttonFlags; }

    IconPosition iconPosition() const { return mIconPosition; }
    void setIconPosition(IconPosition iconPosition) { mIconPosition = iconPosition; }

    bool pushed() const { return mPushed; }
    void setPushed(bool pushed) { mPushed = pushed; }

    /// Set the push callback (for any type of button)
    std::function<void()> callback() const { return mCallback; }
    void setCallback(const std::function<void()> &callback) { mCallback = callback; }

    /// Set the change callback (for toggle buttons)
    std::function<void(bool)> changeCallback() const { return mChangeCallback; }
    void setChangeCallback(const std::function<void(bool)> &callback) { mChangeCallback = callback; }

    /// On Focus
    std::function<void()> onForcusCallback() const { return mOnFocusCallback; }
    void setOnSetFocusCallback(const std::function<void()> &callback) { mOnFocusCallback = callback; }

    /// On Focus
    std::function<void()> onLeaveCallback() const { return mOnLeaveCallback; }
    void setOnLeaveCallback(const std::function<void()> &callback) { mOnLeaveCallback = callback; }

    /// Set the button group (for radio buttons)
    void setButtonGroup(const std::vector<Button *> &buttonGroup) { mButtonGroup = buttonGroup; }
    const std::vector<Button *> &buttonGroup() const { return mButtonGroup; }

    virtual Vector2i preferredSize(NVGcontext *ctx) const override;
    virtual bool mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers) override;
    virtual bool mouseEnterEvent(const Vector2i &p, bool enter) override;
    virtual void draw(NVGcontext *ctx) override;

    virtual void save(Serializer &s) const override;
    virtual bool load(Serializer &s) override;

    Button& withCallback(const std::function<void()> &callback) { setCallback( callback ); return *this; }
    Button& withFlags(int flags) { setFlags( flags); return *this; }
    Button& withChangeCallback(const std::function<void(bool)>& callback) { setChangeCallback( callback ); return *this; }
    Button& withBackgroundColor(const Color& color) { setBackgroundColor( color ); return *this; }
    Button& withIcon(int icon) { setIcon( icon ); return *this; }
protected:
    std::string mCaption;
    int mIcon;
    IconPosition mIconPosition;
    bool mPushed;
    int mFlags;
    Color mBackgroundColor;
    Color mTextColor;
    std::function<void()> mCallback;
    std::function<void(bool)> mChangeCallback;
    std::function<void()> mOnFocusCallback;
    std::function<void()> mOnLeaveCallback;
    
    std::vector<Button *> mButtonGroup;
};


class NANOGUI_EXPORT ImageButton : public Button {
public:
  ImageButton(Widget *parent, const std::string &caption = "Untitled", int icon = 0);

  virtual Vector2i preferredSize(NVGcontext *ctx) const override;
  virtual void draw(NVGcontext *ctx) override;

  std::function<int(int id, int x, int y, int w, int h)> onImageRequested() const { return mOnImageRequested; }
  void setOnImageRequested(const std::function<int(int id, int x, int y, int w, int h)> &callback) { mOnImageRequested = callback; }

protected:
  int imageHeight;
  std::function<int(int id, int x, int y, int w, int h)> mOnImageRequested;

};

NAMESPACE_END(nanogui)
