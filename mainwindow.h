#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QLabel>
#include <QTranslator>

#include <opencv2/core/core.hpp>
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Settigns ---------------------------------
    QString dataFolder, resultsFolder;
    int languageSet, temaDefault;

    // Reporte ----------------------------------
    QStringList reportTexts;

private slots:
    // Configuración
    void on_btnDatosFolderPath_clicked();
    void on_btnResultsFolderPath_clicked();
    void on_languageComboBox_activated(int index);
    void on_temaComboBox_currentIndexChanged(int index);

    // Archivo
    void on_btnNuevoEstudio_clicked();
    void on_btnGenerarReporte_clicked();

    // Ayuda
    void on_manualButton_clicked();
    void on_aboutButton_clicked();
    void on_aboutQtButton_clicked();

    // Paciente
    void on_btnNuevo_clicked();
    void on_btnCargar_clicked();
    void on_btnGuardar_clicked();

    // Datos
    void on_editApellidos_textChanged(const QString &arg1);
    void on_editNombres_textChanged(const QString &arg1);
    void on_spinPeso_valueChanged(double arg1);
    void on_spinAltura_valueChanged(double arg1);
    void on_cmbxPeso_currentIndexChanged(int index);
    void on_cmbxAltura_currentIndexChanged(int index);
    void on_editOcupacion_textChanged(const QString &arg1);
    void on_editProyecto_textChanged(const QString &arg1);
    void on_editEvaluador_textChanged(const QString &arg1);

    void on_btnCalcular_clicked();

    void on_editParam1_textChanged(double &arg1);

    void on_editParam2_textChanged(double &arg1);

    void on_editParam3_textChanged(double &arg1);

    void on_editParam4_textChanged(double &arg1);

    void on_editParam6_textChanged(double &arg1);

    void on_editParam7_textChanged(double &arg1);

    void on_editParam8_textChanged(double &arg1);

    void on_editParam9_textChanged(double &arg1);

    void on_editParam10_textChanged(double &arg1);

    void on_editParam11_textChanged(double &arg1);

private:
    Ui::MainWindow *ui;

    QTranslator T;
};

#endif // MAINWINDOW_H
