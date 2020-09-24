﻿#pragma once

#include "gui/panels/mainpanel/thumbnailstrip.h"

struct ThumbnailStripStateBuffer {
    QList<int> selection = {-1};
    int itemCount;
};

class ThumbnailStripProxy : public QWidget, public IDirectoryView {
    Q_OBJECT
    Q_INTERFACES(IDirectoryView)
public:
    ThumbnailStripProxy(QWidget *parent = nullptr);
    void init();

public slots:
    virtual void populate(int) Q_DECL_OVERRIDE;
    virtual void setThumbnail(int pos, std::shared_ptr<Thumbnail> thumb) Q_DECL_OVERRIDE;
    virtual void select(QList<int>) Q_DECL_OVERRIDE;
    virtual void select(int) override;
    virtual QList<int> selection() Q_DECL_OVERRIDE;
    virtual void focusOn(int) Q_DECL_OVERRIDE;
    virtual void insertItem(int index) Q_DECL_OVERRIDE;
    virtual void removeItem(int index) Q_DECL_OVERRIDE;
    virtual void reloadItem(int index) Q_DECL_OVERRIDE;
    virtual void setDirectoryPath(QString path) Q_DECL_OVERRIDE;
    void addItem();

protected:
    void showEvent(QShowEvent *event) override;

signals:
    void itemActivated(int) override;
    void thumbnailsRequested(QList<int>, int, bool, bool) override;
    void draggedOut(QList<int>) override;
    void draggedToBookmarks(QList<int>) override;

private:
    std::shared_ptr<ThumbnailStrip> thumbnailStrip;
    QVBoxLayout layout;
    ThumbnailStripStateBuffer stateBuf;
};
