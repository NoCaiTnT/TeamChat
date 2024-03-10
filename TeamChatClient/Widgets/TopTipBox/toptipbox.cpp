#include "toptipbox.h"

TopTipBox* TopTipBox::toptipbox_instance_ = NULL;

TopTipBox::TopTipBox(){

}

TopTipBox::TopTipBox(QWidget *parent) : QWidget{parent} {
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setTopTipBoxSize();
    initControls();
    initConnects();
    setTopTipBoxAutoSize();
    setStyle(":/StyleSheet/TopTipBox/info_style.qss");
}


void TopTipBox::initControls() {
    //定时器
    timer_show_timeout_ = new QTimer(this);
    timer_show_timeout_->setSingleShot(true);
    //图标
    label_icon_ = new QLabel(this);
    label_icon_->setObjectName("icon");
    //内容
    label_text_ = new QLabel(this);
    label_text_->setObjectName("text");
    //本身
    widget_this_ = new QWidget(this);
    widget_this_->setObjectName("this-widget");

    //布局
    QHBoxLayout *bottom_layer = new QHBoxLayout(this);
    bottom_layer->setContentsMargins(5,5,5,5);
    bottom_layer->addWidget(widget_this_);

    QHBoxLayout *totalH = new QHBoxLayout(widget_this_);
    totalH->addStretch();
    totalH->addWidget(label_icon_);
    totalH->addWidget(label_text_);
    totalH->addStretch();

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(effect);
}

void TopTipBox::initConnects() {
    connect(timer_show_timeout_, &QTimer::timeout, this, &TopTipBox::endAnimation);
}

void TopTipBox::showTopTipBox(QWidget *parent, TipBoxType type, const QString &text) {

    QWidget::hide();
    timer_show_timeout_->stop();

    updateUI(type, text);
    widget_parent_ = getRootWidget(parent);
    this->setParent(widget_parent_);
    widget_parent_->installEventFilter(this);

    QWidget::show();
    beginAnimation();

}

void TopTipBox::beginAnimation() {
    // 开始动画
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect((widget_parent_->width() - this->width())/2, 0, this->width(), this->height()));
    animation1->setEndValue(QRect((widget_parent_->width() - this->width())/2, 50, this->width(), this->height()));
    QPropertyAnimation *animation2 = new QPropertyAnimation(this->graphicsEffect(), "opacity");
    animation2->setDuration(250);
    animation2->setStartValue(0.0);
    animation2->setEndValue(1);

    animation1->start();
    animation2->start();

    timer_show_timeout_->start(2000);
}

void TopTipBox::endAnimation() {
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(100);
    animation1->setEndValue(QRect((widget_parent_->width()-this->width())/2, 0, this->width(), this->height()));
    animation1->setStartValue(QRect((widget_parent_->width()-this->width())/2, 50, this->width(), this->height()));

    QPropertyAnimation *animation2 = new QPropertyAnimation(this->graphicsEffect(), "opacity");
    animation2->setDuration(150);
    animation2->setStartValue(1);
    animation2->setEndValue(0);

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start();

    connect(group, &QParallelAnimationGroup::finished, this, [=](){
        this->deleteLater();
        toptipbox_instance_ = NULL;
    });
}

void TopTipBox::updateUI(TipBoxType type, const QString &text) {
    if (auto_size_ == true) {
        QFont font("Microsoft YaHei");
        QFontMetrics fontMetrics(font);
        int width = fontMetrics.horizontalAdvance(text);
        this->setFixedWidth(width + 70);
    }
    switch (type) {
        case INFO: {
            label_text_->setText(text);
            setIcon(":/Resources/TopTipBox/info_icon.png", 24);
            setStyle(":/StyleSheet/TopTipBox/info_style.qss");
            break;
        }
        case WARNING: {
            label_text_->setText(text);
            setIcon(":/Resources/TopTipBox/warning_icon.png", 24);
            setStyle(":/StyleSheet/TopTipBox/warning_style.qss");
            break;
        }
        case ERROR: {
            label_text_->setText(text);
            setIcon(":/Resources/TopTipBox/error_icon.png", 24);
            setStyle(":/StyleSheet/TopTipBox/error_style.qss");
            break;
        }
    }

}

void TopTipBox::setIcon(QString url, int size) {
    QPixmap avatar = QPixmap(url);
    QPixmap pixmap(size,size);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0,0,size,size);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,size,size,avatar);
    label_icon_->setFixedSize(size,size);
    label_icon_->setScaledContents(true);
    label_icon_->setPixmap(pixmap);
}

void TopTipBox::setStyle(QString path) {
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

QWidget *TopTipBox::getRootWidget(QWidget *widget) {
    QWidget *rootWidget = widget;
    while (rootWidget->parent())
    {
        rootWidget = (QWidget *)rootWidget->parent();
    }
    return rootWidget;
}

void TopTipBox::closeAll() {
    this->deleteLater();
    toptipbox_instance_ = NULL;
}

void TopTipBox::showInformationTopTipBox(QWidget *parent, const QString &text) {
    if (toptipbox_instance_ == NULL) toptipbox_instance_ = new TopTipBox(parent);
    toptipbox_instance_->showTopTipBox(parent, INFO, text);
}

void TopTipBox::showWarningTopTipBox(QWidget *parent, const QString &text) {
    if (toptipbox_instance_ == NULL) toptipbox_instance_ = new TopTipBox(parent);
    toptipbox_instance_->showTopTipBox(parent, WARNING, text);
}

void TopTipBox::showErrorTopTipBox(QWidget *parent, const QString &text) {
    if (toptipbox_instance_ == NULL) toptipbox_instance_ = new TopTipBox(parent);
    toptipbox_instance_->showTopTipBox(parent, ERROR, text);
}

void TopTipBox::setTopTipBoxSize(QSize size) {
    this->setFixedSize(size);
}

void TopTipBox::setTopTipBoxAutoSize(bool autosize) {
    auto_size_ = autosize;
}

bool TopTipBox::eventFilter(QObject *watched, QEvent *event) {
    if (watched == widget_parent_ && event->type() == QEvent::Resize) {
        QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);
        QPoint pos((widget_parent_->width() - this->width())/2, this->y());
        move(pos);
        return true;
    }
    return QWidget::eventFilter(watched, event);
}
