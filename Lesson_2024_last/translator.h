#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QCoreApplication>
#include <QTranslator>


class Translator {
  public:
    static Translator& get();
  private:
    Translator();

    Translator(const Translator&) = delete;
    Translator& operator=(const Translator&) = delete;

  private:
    QTranslator translator;
  public:
    void set(QString lang);
};

#endif // TRANSLATOR_H
