#include "gestion.h"
#include "ui_gestion.h"
#include "commande.h"
#include "livraison.h"
#include "notification.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    refresh();
    connect(ui->sendBtn_3, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn_3, SIGNAL(clicked()),this, SLOT(close()));
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sendMail()
{
Smtp* smtp = new Smtp(ui->uname_3->text(), ui->paswd_3->text(), ui->server_3->text(), ui->port_3->text().toUShort());
connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


smtp->sendMail(ui->uname_3->text(), ui->rcpt_3->text() , ui->subject_3->text(),ui->msg_3->toPlainText());
}

void MainWindow::mailSent(QString status)
{
if(status == "Message sent")
    QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message envoye !\n\n" ) );
}
void MainWindow::refresh()
{
  ui->tabemployer->setModel(tmpcmd.afficher_commande());
  ui->comboBox_3->setModel(tmpcmd.afficher_list());
  ui->comboBox_5->setModel(tmpcmd.afficher_list());
  ui->tabconge->setModel(tmppaiement.afficher_paiement());
  ui->comboBox_4->setModel(tmppaiement.afficher_list());
  ui->comboBox_6->setModel(tmppaiement.afficher_list());
}

void MainWindow::on_ajouter_clicked()
{
    QString idcmd=ui->cin->text();
    QString datecmd=ui->nom->text();
    QString idclient=ui->idclient->currentText();

    QString idp=ui->idp->currentText();

    commande e(idcmd,datecmd,idclient,idp);
    bool test=e.ajouter_commande();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " commande ajouté");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", " commande non ajouté ");
    }


    ui->tabemployer->setModel(tmpcmd.afficher_commande());
    refresh();
}



void MainWindow::on_supprimer_clicked()
{

    QString idcmd = ui->sup->text();
     commande e;
     e.setidcmd(idcmd);
     bool test=e.supprimer_commande();
     if(test)
     {   refresh();
         QMessageBox::information(this, "PAS D'ERREUR", "commande supprimé");
            QString okd="";

        N.notification_sup_cmd();
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "commande supprimé ");
     }

    ui->sup->clear();


}



void MainWindow::on_modifier_2_clicked()
{
    tmpcmd.setdatecmd(ui->nom_4->text());
    tmpcmd.setidclient(ui->prenom_4->text());
    tmpcmd.setidp(ui->matricule_4->text());



    bool test=tmpcmd.modifier_commande();
    if(test){
            QMessageBox::information(this, "PAS D'ERREUR", " commande modifié");
        }
        else
        {
            QMessageBox::critical(this, " ERREUR ", "commande non modifié ");
        }
    refresh();

}



void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmpcmd.setidcmd(arg1);
    tmpcmd.chercher();
    ui->nom_4->setText(tmpcmd.getdatecmd());
    ui->prenom_4->setText(tmpcmd.getidclient());
    ui->matricule_4->setText(tmpcmd.getidp());
    refresh();


}

void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);

}



void MainWindow::on_lineEdit_19_textChanged(const QString &arg1)
{
    ui->tabemployer->setModel(tmpcmd.recherche(arg1,etat));
    valeur=arg1;

}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabemployer->setModel(tmpcmd.recherche(valeur,etat));

}

//paiement

void MainWindow::on_ajouter_2_clicked()
{   QString nump=ui->num_conge->text();
    QString datep=ui->date_debut->text();
    QString montant=ui->date_fin->text();
    QString typep=ui->type_3->text();
    QString idpr=ui->idprod->currentText();

    paiement g(nump,datep,montant,typep,idpr);
    bool test=g.ajouter_paiement();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " paiement ajouté");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", "paiement non ajouté ");
    }


    ui->tabconge->setModel(tmppaiement.afficher_paiement());
    refresh();

}

void MainWindow::on_supprimer_2_clicked()
{

    QString nump = ui->sup_2->text();
     paiement g;
     g.setnump(nump);
     bool test=g.supprimer_paiement();
     if(test)
     {   refresh();
         QMessageBox::information(this, "PAS D'ERREUR", "paiement supprimé");
         QString okd="";
          N.notification_sup_paiement();
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "paiement supprimé ");
     }

    ui->sup->clear();
}

void MainWindow::on_comboBox_6_activated(const QString &arg1)
{
   ui->sup_2->setText(arg1);
}





void MainWindow::on_modifier_3_clicked()
{
    tmppaiement.setdatep(ui->nom_5->text());
    tmppaiement.setmontant(ui->prenom_5->text());
    tmppaiement.settypep(ui->matricule_5->text());
    tmppaiement.setidpr(ui->age_5->text());


    bool test=tmppaiement.modifier_paiement();

 if(test){ refresh();
         QMessageBox::information(this, "PAS D'ERREUR", " paiement modifié");
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "paiement non modifié ");
     }

}



void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    tmppaiement.setnump(arg1);
    tmppaiement.chercher();
    ui->nom_5->setText(tmppaiement.getdatep());
    ui->prenom_5->setText(tmppaiement.getmontant());
    ui->matricule_5->setText(tmppaiement.gettypep());
    ui->age_5->setText(tmppaiement.getidpr());

}

void MainWindow::on_lineEdit_20_textChanged(const QString &arg1)
{
    ui->tabconge->setModel(tmppaiement.recherche(arg1,etat));
    valeur=arg1;
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
     etat=arg1;
     ui->tabconge->setModel(tmppaiement.recherche(valeur,etat));

}

/*void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlot->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
         // amande->setName("Repartition des reservation selon les destinations");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;
          tmppaiement.statistique(&ticks,&labels);



          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlot->xAxis->setTicker(textTicker);
          ui->customPlot->xAxis->setTickLabelRotation(60);
          ui->customPlot->xAxis->setSubTicks(false);
          ui->customPlot->xAxis->setTickLength(0, 4);
          ui->customPlot->xAxis->setRange(0, 8);
          ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->xAxis->grid()->setVisible(true);
          ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlot->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlot->yAxis->setRange(0,10);
          ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlot->yAxis->setLabel("Statistiques");
          ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->grid()->setSubGridVisible(true);
          ui->customPlot->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot->yAxis->setLabelColor(Qt::white);
          ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select nump from paiement");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlot->legend->setVisible(true);
          ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlot->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlot->legend->setFont(legendFont);
          ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


  refresh();
} */
///////livraisons
void MainWindow::on_ajouter_liv_clicked()
{
    QString idliv=ui->cin_2->text();
    QString dateliv=ui->nom_2->text();
    //QString idclient=ui->prenom_2->text();

 //   QString idp=ui->matricule_2->text();
    //int numliv=ui->idcmd->text().toInt();
     QString idcmd=ui->idprod->currentText();//hedhi matmeshech
    livraison e(idliv,dateliv,idcmd);
    bool test=e.ajouter_livraison();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " livraison ajoutée");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", " livraison non ajoutée ");
    }


    ui->tabliv->setModel(tmpliv.afficher_livraison());
    refresh();
}
void MainWindow::on_supprimer_liv_clicked()
{

     QString idliv = ui->sup_2->text();
     livraison e;
     e.setidliv(idliv);
     bool test=e.supprimer_livraison();
     if(test)
     {   refresh();
         QMessageBox::information(this, "PAS D'ERREUR", "livraison supprimée");

     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "livraison supprimée ");
     }

    ui->sup_2->clear();


}
void MainWindow::on_modifier_liv_clicked()
{

    tmpliv.setdateliv(ui->nom_6->text());
    tmpliv.setidcmd(ui->prenom_6->text());



    bool test=tmpliv.modifier_livraison();
    if(test){
            QMessageBox::information(this, "PAS D'ERREUR", " livraison modifié");
        }
        else
        {
            QMessageBox::critical(this, " ERREUR ", "livraison non modifiée ");
        }
    refresh();

}
void MainWindow::on_comboBox_7_activated(const QString &arg1)
{
    tmpliv.setidliv(arg1);
    tmpliv.chercher();
    ui->nom_6->setText(tmpliv.getdateliv());
    ui->prenom_6->setText(tmpliv.getidcmd());

    refresh();


}

void MainWindow::on_comboBox_8_activated(const QString &arg1)
{
    ui->sup->setText(arg1);

}



void MainWindow::on_lineEdit_21_textChanged(const QString &arg1)
{
    ui->tabemployer->setModel(tmpcmd.recherche(arg1,etat));
    valeur=arg1;

}



void MainWindow::on_checkBox_4_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabliv->setModel(tmpliv.recherche(valeur,etat));

}



void MainWindow::on_pushButton_clicked()
{
     ui->idprod->setModel(tmppaiement.afficher_prod());
}

void MainWindow::on_refreshaff_clicked()
{
     ui->idprod2->setModel(tmppaiement.afficher_prod());

}

void MainWindow::on_view_clicked()
{
    int idproduit = ui->idprod2->currentText().toInt();
    ui->tabconge->setModel(tmppaiement.recherche2(idproduit));
}

void MainWindow::on_refresh2_clicked()
{
    ui->idclient->setModel(tmpcmd.afficher_client());
    ui->idp->setModel(tmpcmd.afficher_p());
}

void MainWindow::on_refreshliv_clicked()
{
   ui->idcmd->setModel(tmpliv.afficher_livraison());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->comboBox_7->setModel(tmpliv.afficher_livraison());

}

