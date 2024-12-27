#include "translator.h"

Translator::Translator() {
    qApp->installTranslator(&translator);
}



Translator& Translator::get() {
    static Translator tr;
    return tr;
}

void Translator::set(QString lang) {
    QString path = QString(":/i18n/Lesson_2024_last_%1.qm").arg(lang);
    if (!translator.load(path)) {

    }
}
