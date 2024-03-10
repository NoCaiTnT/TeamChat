#include "masklayer.h"

MaskLayer::MaskLayer(QWidget *parent) : QWidget{parent} {
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setMaskColor("black", 0.3);
    widget_parrent_ = QApplication::activeWindow();
}

void MaskLayer::setChildWidget(QWidget *widget) {
    if (widget == nullptr) return;
    widget->installEventFilter(this);
    widget_child_ = widget;
    connect(widget_child_, &QWidget::destroyed, this, [=](){
        widget_child_ = nullptr;
    });
}

void MaskLayer::setParentWidget(QWidget *widget) {
    if (widget == nullptr) return;
    widget_parrent_ = widget;
}

void MaskLayer::setMaskColor(const QColor &color, float opacity) {
    if (!color.isValid()) return;

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, color);
    this->setPalette(palette);

    setWindowOpacity(opacity);
}

void MaskLayer::setMaskSize(int leftDiff, int topDiff, int rightDiff, int downDiff) {
    if(leftDiff > widget_parrent_->width()) leftDiff_ = widget_parrent_->width() / 2;
    if(leftDiff < 0)  leftDiff_ = 0;
    if(topDiff > widget_parrent_->width()) topDiff_ = widget_parrent_->height() / 2;
    if(topDiff < 0)  topDiff_ = 0;
    if(rightDiff > widget_parrent_->width()) rightDiff_ = widget_parrent_->width() / 2;
    if(rightDiff < 0)  rightDiff_ = 0;
    if(downDiff > widget_parrent_->width()) downDiff_ = widget_parrent_->height() / 2;
    if(downDiff < 0)  downDiff_ = 0;
}

void MaskLayer::showEvent(QShowEvent *event) {
    Q_UNUSED(event);
    this->setGeometry(widget_parrent_->geometry().x() + leftDiff_,
                      widget_parrent_->geometry().y() + topDiff_,
                      widget_parrent_->geometry().width() - (leftDiff_ + rightDiff_),
                      widget_parrent_->geometry().height() - (topDiff_ + downDiff_));
}

bool MaskLayer::eventFilter(QObject *watched, QEvent *event) {
    if (watched == widget_child_) {
        if (event->type() == QEvent::Show) {
            this->show();
        }

        if (event->type() == QEvent::Hide) {
            this->hide();
        }
    }

    return QObject::eventFilter(watched, event);
}
