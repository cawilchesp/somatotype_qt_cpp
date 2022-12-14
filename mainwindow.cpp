#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //---------------------------- Valores de Configuración -----------------------------
    QSettings somatotipoSettings("config.ini" , QSettings::IniFormat);
    dataFolder = somatotipoSettings.value("Data_Folder","C:\\").toString();
    resultsFolder = somatotipoSettings.value("Results_Folder","C:\\").toString();
    languageSet = somatotipoSettings.value("Language",0).toInt();
    temaDefault = somatotipoSettings.value("Theme",0).toInt();
    reportTexts = somatotipoSettings.value("Report_Texts").toStringList();

    ui->lblDatosFolderPath->setText(dataFolder);
    ui->lblResultsFolderPath->setText(resultsFolder);

    QRegExp regExp1 ("[A-Za-zÁÉÍÓÚáéíóú ]{1,44}");
    ui->editApellidos->setValidator(new QRegExpValidator (regExp1, this));
    ui->editNombres->setValidator(new QRegExpValidator (regExp1, this));
    ui->editOcupacion->setValidator(new QRegExpValidator (regExp1, this));
    ui->editProyecto->setValidator(new QRegExpValidator (regExp1, this));
    ui->editEvaluador->setValidator(new QRegExpValidator (regExp1, this));

    QRegExp regExp2 ("[0-9]{1,2}");
    ui->editId->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam1->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam2->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam3->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam4->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam6->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam7->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam8->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam9->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam10->setValidator(new QRegExpValidator (regExp2, this));
    ui->editParam11->setValidator(new QRegExpValidator (regExp2, this));

    // -------------------------- Configuración de las gráficas -------------------------
    ui->plotSomatotipo->yAxis->setRange(-8,16);
    ui->plotSomatotipo->yAxis->setAutoTickStep(false);
    ui->plotSomatotipo->yAxis->setTickStep(1);
    ui->plotSomatotipo->xAxis->setRange(-8,8);
    ui->plotSomatotipo->xAxis->setAutoTickStep(false);
    ui->plotSomatotipo->xAxis->setTickStep(1);

    QVector<double> line1X = {-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8};
    QVector<double> line1Y = {8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8};
    QVector<double> line2X = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    QVector<double> line2Y = {-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    QVector<double> line3X = {-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8};
    QVector<double> line3Y = {-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8};

    QVector<double> line4X = {6,6,5.67409761270664,5.49399314378803,5.22087335404258,4.86351653823642,4.43340843846373,3.94437308294532,3.41212847038720,2.85378138056930,2.28727754836789,1.73082487307083,1.20230820151295,0.718714494383080,0.35,0,0};
    QVector<double> line4Y = {-6,-5.80763825313831,-4.3,-3.57571008871443,-2.36898744497220,-0.989701127130974,0.517817467673262,2.10511545141307,3.72117576085792,5.31405688796341,6.83256232267740,8.22788605089775,9.45518121992329,10.4750015531997,11.2545691861045,12,12};
    QVector<double> line5X = {-6,-6,-5.67409761270664,-5.49399314378803,-5.22087335404258,-4.86351653823642,-4.43340843846373,-3.94437308294532,-3.41212847038720,-2.85378138056930,-2.28727754836789,-1.73082487307083,-1.20230820151295,-0.718714494383080,-0.35,0,0};
    QVector<double> line6X = {-6,-5.78377716417512,-5.40581320741452,-4.85410196624969,-4.14637589392119,-3.30538188871262,-2.35815018992354,-1.33512560373788,-0.269188982103091,0.805399594905932,1.85410196624968,2.84321197483799,3.74093881115240,4.51842879602167,5.15069276161120,5.61740922383842,5.90357753159178,6};
    QVector<double> line6Y = {-6,-6.26603684556668,-6.43388373911756,-6.58778525229247,-6.72279486382739,-6.83457325372130,-6.91952777255145,-6.97492791218182,-6.99899306654131,-6.99094976176794,-6.95105651629515,-6.88059553185674,-6.78183148246803,-6.65793872593971,-6.51289927740591,-6.35137482408134,-6.17855689479864,-6};

    ui->plotSomatotipo->addGraph();
    ui->plotSomatotipo->graph(0)->setData(line1X, line1Y);
    ui->plotSomatotipo->graph(0)->setPen(QPen(QColor(217, 83, 25), 1, Qt::DashLine));
    ui->plotSomatotipo->addGraph();
    ui->plotSomatotipo->graph(1)->setData(line2X, line2Y);
    ui->plotSomatotipo->graph(1)->setPen(QPen(QColor(217, 83, 25), 1, Qt::DashLine));
    ui->plotSomatotipo->addGraph();
    ui->plotSomatotipo->graph(2)->setData(line3X, line3Y);
    ui->plotSomatotipo->graph(2)->setPen(QPen(QColor(217, 83, 25), 1, Qt::DashLine));
    ui->plotSomatotipo->addGraph();
    ui->plotSomatotipo->graph(3)->setData(line4X, line4Y);
    ui->plotSomatotipo->graph(3)->setPen(QPen(QColor(0, 114, 189)));
    ui->plotSomatotipo->addGraph();
    ui->plotSomatotipo->graph(4)->setData(line5X, line4Y);
    ui->plotSomatotipo->graph(4)->setPen(QPen(QColor(0, 114, 189)));
    ui->plotSomatotipo->addGraph();
    ui->plotSomatotipo->graph(5)->setData(line6X, line6Y);
    ui->plotSomatotipo->graph(5)->setPen(QPen(QColor(0, 114, 189)));

    ui->plotSomatotipo->replot();

    // ------------------------------ Definición del idioma -----------------------------
//    T.load(":/traducciones/ingles.qm");
    ui->languageComboBox->setCurrentIndex(languageSet);
    on_languageComboBox_activated(languageSet);

    // ------------------------------- Definición del tema ------------------------------
    ui->temaComboBox->setCurrentIndex(temaDefault);
    on_temaComboBox_currentIndexChanged(temaDefault);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------------------------------------------------------------------------------
// SETTINGS
// ---------------------------------------------------------------------------------------

void MainWindow::on_btnDatosFolderPath_clicked()
{
    //----------------------------- Selección de la carpeta -----------------------------
    QString dataFolderTemp = dataFolder;
    dataFolderTemp = QFileDialog::getExistingDirectory(this, tr("Seleccione la carpeta con los archivos de datos"), dataFolder, QFileDialog::ShowDirsOnly);
    if (dataFolderTemp != "") {
        dataFolder = dataFolderTemp;
    }
    ui->lblDatosFolderPath->setText(dataFolder);
    QSettings somatotipoSettings("config.ini" , QSettings::IniFormat);
    somatotipoSettings.setValue("Data_Folder", dataFolder);
}

void MainWindow::on_btnResultsFolderPath_clicked()
{
    //----------------------------- Selección de la carpeta -----------------------------
    QString resultsFolderTemp = resultsFolder;
    resultsFolderTemp = QFileDialog::getExistingDirectory(this, tr("Seleccione la carpeta donde se guardarán los resultados"), resultsFolder, QFileDialog::ShowDirsOnly);
    if (resultsFolderTemp != "") {
        resultsFolder = resultsFolderTemp;
    }
    ui->lblResultsFolderPath->setText(resultsFolder);
    QSettings somatotipoSettings("config.ini" , QSettings::IniFormat);
    somatotipoSettings.setValue("Results_Folder", resultsFolder);
}

void MainWindow::on_languageComboBox_activated(int index)
{
    //---------------------------------- Configuración ----------------------------------
    QSettings somatotipoSettings("config.ini" , QSettings::IniFormat);
    languageSet = somatotipoSettings.value("Language",0).toInt();

    //------------------------------ Definición del idioma ------------------------------
    if (index == 0) {
        languageSet = 0;

//        qApp->removeTranslator(&T);
//        ui->retranslateUi(this);
    } else if (index == 1) {
        languageSet = 1;

//        qApp->installTranslator(&T);
//        ui->retranslateUi(this);
    }
    somatotipoSettings.setValue("Language",languageSet);
}

void MainWindow::on_temaComboBox_currentIndexChanged(int index)
{

}

// ---------------------------------------------------------------------------------------
// MENU
// ---------------------------------------------------------------------------------------

void MainWindow::on_btnNuevoEstudio_clicked()
{
    // Reajustar campos de datos --------------------------------------------------------
    ui->editParam1->clear();
    ui->editParam1->setEnabled(true);
    ui->editParam2->clear();
    ui->editParam2->setEnabled(true);
    ui->editParam3->clear();
    ui->editParam3->setEnabled(true);
    ui->editParam4->clear();
    ui->editParam4->setEnabled(true);
    ui->editParam6->clear();
    ui->editParam6->setEnabled(true);
    ui->editParam7->clear();
    ui->editParam7->setEnabled(true);
    ui->editParam8->clear();
    ui->editParam8->setEnabled(true);
    ui->editParam9->clear();
    ui->editParam9->setEnabled(true);
    ui->editParam10->clear();
    ui->editParam10->setEnabled(true);
    ui->editParam11->clear();
    ui->editParam11->setEnabled(true);
    ui->editParam1->setFocus();

    // Reajustar botones ----------------------------------------------------------------
    ui->btnCalcular->setEnabled(false);
    ui->btnGenerarReporte->setEnabled(false);
}

void MainWindow::on_btnGenerarReporte_clicked()
{

}

// --------------------------------------------------------------------------------------
// AYUDA
// --------------------------------------------------------------------------------------

void MainWindow::on_manualButton_clicked()
{

}

void MainWindow::on_aboutButton_clicked()
{
    QString message = tr("SOMATOTIPO V1.0\n"
                      "\n"
                      "Desarrollado por:\n"
                      "\n"
                      "CARLOS ANDRÉS WILCHES PÉREZ\n"
                      "INGENIERO ELECTRÓNICO, MSc.\n"
                      "Contacto: c.wilches@javeriana.edu.co\n"
                      "\n"
                      "PONTIFICIA UNIVERSIDAD JAVERIANA\n"
                      "FACULTAD DE INGENIERÍA\n"
                      "DEPARTAMENTO DE INGENIERÍA ELECTRÓNICA\n"
                      "\n"
                      "2019");

    //------------------------------- Mensaje Acerca de... ------------------------------
    QMessageBox about;
    about.setWindowTitle(tr("Acerca de..."));
    about.setWindowIcon(QIcon(QPixmap(":/imagenes/Imagenes/Icono.png")));
    about.setText(message);
    about.setIconPixmap(QPixmap(":/imagenes/Imagenes/escudoPuj.png"));
    about.setStandardButtons(QMessageBox::Ok);
    about.setDefaultButton(QMessageBox::Ok);
    about.setStyleSheet("QLabel{min-width: 300px;}");
    about.exec();
}

void MainWindow::on_aboutQtButton_clicked()
{
    QMessageBox::aboutQt(this, tr("Acerca de Qt"));
}

// ----------------------------------------------------------------------------------------
// DATOS
// ----------------------------------------------------------------------------------------

void MainWindow::on_btnNuevo_clicked()
{
    // Reajustar campos de datos --------------------------------------------------------
    ui->editApellidos->clear();
    ui->editApellidos->setEnabled(true);
    ui->editNombres->clear();
    ui->editNombres->setEnabled(true);
    ui->cmbxId->setCurrentIndex(-1);
    ui->cmbxId->setEnabled(true);
    ui->editId->clear();
    ui->editId->setEnabled(true);
    ui->dateNacimiento->setDate(QDate(2000,1,1));
    ui->dateNacimiento->setEnabled(true);
    ui->cmbxGenero->setCurrentIndex(-1);
    ui->cmbxGenero->setEnabled(true);
    ui->spinPeso->setValue(0);
    ui->spinPeso->setEnabled(true);
    ui->cmbxPeso->setCurrentIndex(-1);
    ui->cmbxPeso->setEnabled(true);
    ui->spinAltura->setValue(0);
    ui->spinAltura->setEnabled(true);
    ui->cmbxAltura->setCurrentIndex(-1);
    ui->cmbxAltura->setEnabled(true);
    ui->lblBMI->clear();
    ui->dateSesion->setDate(QDate(2000,1,1));
    ui->dateSesion->setEnabled(true);
    ui->editOcupacion->clear();
    ui->editOcupacion->setEnabled(true);
    ui->editProyecto->clear();
    ui->editProyecto->setEnabled(true);
    ui->editEvaluador->clear();
    ui->editEvaluador->setEnabled(true);

    // Reajustar botones ----------------------------------------------------------------
    ui->btnGuardar->setEnabled(true);
    ui->btnGenerarReporte->setEnabled(false);

    // Establecer campo inicial ---------------------------------------------------------
    ui->editApellidos->setFocus();
}

void MainWindow::on_btnCargar_clicked()
{

}

void MainWindow::on_btnGuardar_clicked()
{
    if (ui->editApellidos->text() == "" || ui->editNombres->text() == "" || ui->cmbxId->currentIndex() == -1 || ui->editId->text() == "" ||
            ui->cmbxGenero->currentIndex() == -1 || ui->cmbxPeso->currentIndex() == -1 || ui->cmbxAltura->currentIndex() == -1 ||
            ui->editOcupacion->text() == "" || ui->editProyecto->text() == "" || ui->editEvaluador->text() == "") {
        QMessageBox *MsgBox = new QMessageBox(QMessageBox::Critical, "Error", tr("Faltan campos de datos por completar"), QMessageBox::Close);
        MsgBox->exec();
    } else {
        QString pesoUnidades;
        if (ui->cmbxPeso->currentIndex() == 0) {
            pesoUnidades = "Kg";
        } else {
            pesoUnidades = "Lb";
        }

        QString alturaUnidades;
        if (ui->cmbxAltura->currentIndex() == 0) {
            alturaUnidades = "m";
        } else {
            alturaUnidades = "ft.in";
        }

        QString textFileName = QFileDialog::getSaveFileName(this, tr("Guardar los datos del sujeto en..."), resultsFolder, tr("Archivos de Texto (*.txt)"));
        if (textFileName != "") {
            QFile file(textFileName);
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << QString("DATOS\tSUJETO\r\n"
                           "APELLIDOS:\t%1\r\n"
                           "NOMBRES:\t%2\r\n"
                           "IDENTIFICACIÓN:\t%3 %4\r\n"
                           "FECHA DE NACIMIENTO:\t%5\r\n"
                           "GÉNERO:\t%6\r\n"
                           "PESO:\t%7 %8\r\n"
                           "ALTURA:\t%9 %10\r\n"
                           "IMC:\t%11\r\n"
                           "FECHA DE SESIÓN:\t%12\r\n"
                           "OCUPACIÓN:\t%13\r\n"
                           "PROYECTO:\t%14\r\n"
                           "EVALUADO POR:\t%15")
                   .arg(ui->editApellidos->text())
                   .arg(ui->editNombres->text())
                   .arg(ui->cmbxId->currentText()).arg(ui->editId->text())
                   .arg(ui->dateNacimiento->text())
                   .arg(ui->cmbxGenero->currentText())
                   .arg(ui->spinPeso->value()).arg(pesoUnidades)
                   .arg(ui->spinAltura->value()).arg(alturaUnidades)
                   .arg(ui->lblBMI->text())
                   .arg(ui->dateSesion->text())
                   .arg(ui->editOcupacion->text())
                   .arg(ui->editProyecto->text())
                   .arg(ui->editEvaluador->text());

            ui->statusBar->showMessage(tr("Datos del sujeto guardados"));
        }
    }
}

void MainWindow::on_editApellidos_textChanged(const QString &arg1)
{
    ui->editApellidos->setText(arg1.toUpper());
}

void MainWindow::on_editNombres_textChanged(const QString &arg1)
{
    ui->editNombres->setText(arg1.toUpper());
}

void MainWindow::on_spinPeso_valueChanged(double arg1)
{
    if ((ui->cmbxPeso->currentIndex() != -1) && (ui->cmbxAltura->currentIndex() != -1)) {
        double pesoKg = 0;
        if (ui->cmbxPeso->currentIndex() == 0) {
            pesoKg = arg1;
        } else {
            pesoKg = arg1 * 0.454;
        }

        double alturaM = 0;
        if (ui->cmbxAltura->currentIndex() == 0) {
            alturaM = ui->spinAltura->value();
        } else {
            double alturaFt = qFloor(ui->spinAltura->value());
            double alturaIn = (ui->spinAltura->value() - alturaFt) * 100;
            alturaM = ((alturaFt * 12) + alturaIn) * 2.54 / 100;
        }
        ui->lblBMI->setText(QString::number(pesoKg / (alturaM * alturaM),'F',1));
        ui->lblValueParam12->setText(QString::number(pesoKg,'F',1));
    }
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_spinAltura_valueChanged(double arg1)
{
    if ((ui->cmbxPeso->currentIndex() != -1) && (ui->cmbxAltura->currentIndex() != -1)) {
        double pesoKg = 0;
        if (ui->cmbxPeso->currentIndex() == 0) {
            pesoKg = ui->spinPeso->value();
        } else {
            pesoKg = ui->spinPeso->value() * 0.454;
        }

        double alturaM = 0;
        if (ui->cmbxAltura->currentIndex() == 0) {
            alturaM = arg1;
        } else {
            double alturaFt = qFloor(arg1);
            double alturaIn = (arg1 - alturaFt) * 100;
            alturaM = ((alturaFt * 12) + alturaIn) * 2.54 / 100;
        }
        ui->lblBMI->setText(QString::number(pesoKg / (alturaM * alturaM),'F',1));
        ui->lblValueParam5->setText(QString::number(alturaM * 100,'F',0));
    }
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_cmbxPeso_currentIndexChanged(int index)
{
    if ((ui->cmbxPeso->currentIndex() != -1) && (ui->cmbxAltura->currentIndex() != -1)) {
        double pesoKg = 0;
        if (index == 0) {
            pesoKg = ui->spinPeso->value();
        } else {
            pesoKg = ui->spinPeso->value() * 0.454;
        }

        double alturaM = 0;
        if (ui->cmbxAltura->currentIndex() == 0) {
            alturaM = ui->spinAltura->value();
        } else {
            double alturaFt = qFloor(ui->spinAltura->value());
            double alturaIn = (ui->spinAltura->value() - alturaFt) * 100;
            alturaM = ((alturaFt * 12) + alturaIn) * 2.54 / 100;
        }
        ui->lblBMI->setText(QString::number(pesoKg / (alturaM * alturaM),'F',1));
        ui->lblValueParam12->setText(QString::number(pesoKg,'F',1));
    }
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_cmbxAltura_currentIndexChanged(int index)
{
    if ((ui->cmbxPeso->currentIndex() != -1) && (ui->cmbxAltura->currentIndex() != -1)) {
        double pesoKg = 0;
        if (ui->cmbxPeso->currentIndex() == 0) {
            pesoKg = ui->spinPeso->value();
        } else {
            pesoKg = ui->spinPeso->value() * 0.454;
        }

        double alturaM = 0;
        if (index == 0) {
            alturaM = ui->spinAltura->value();
        } else {
            double alturaFt = qFloor(ui->spinAltura->value());
            double alturaIn = (ui->spinAltura->value() - alturaFt) * 100;
            alturaM = ((alturaFt * 12) + alturaIn) * 2.54 / 100;
        }
        ui->lblBMI->setText(QString::number(pesoKg / (alturaM * alturaM),'F',1));
        ui->lblValueParam5->setText(QString::number(alturaM * 100,'F',0));
    }
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editOcupacion_textChanged(const QString &arg1)
{
    ui->editOcupacion->setText(arg1.toUpper());
}

void MainWindow::on_editProyecto_textChanged(const QString &arg1)
{
    ui->editProyecto->setText(arg1.toUpper());
}

void MainWindow::on_editEvaluador_textChanged(const QString &arg1)
{
    ui->editEvaluador->setText(arg1.toUpper());
}

// ----------------------------------------------------------------------------------------
// CÁLCULO
// ----------------------------------------------------------------------------------------

void MainWindow::on_editParam1_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam2_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam3_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam4_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam6_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam7_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam8_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam9_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam10_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_editParam11_textChanged(double &arg1)
{
    if (ui->editParam1->text() == "" || ui->editParam2->text() == "" || ui->editParam3->text() == "" || ui->editParam4->text() == "" || ui->editParam6->text() == "" || ui->editParam7->text() == ""
             || ui->editParam8->text() == "" || ui->editParam9->text() == "" || ui->editParam10->text() == "" || ui->editParam11->text() == "" || ui->lblValueParam5->text() == "" || ui->lblValueParam12->text() == "") {
        ui->btnCalcular->setEnabled(false);
    } else {
        ui->btnCalcular->setEnabled(true);
    }
}

void MainWindow::on_btnCalcular_clicked()
{

}

// ----------------------------------------------------------------------------------------
// FUNCIONES
// ----------------------------------------------------------------------------------------

