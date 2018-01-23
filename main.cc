#include "Helpers.hh"
#include "coordinate.hh"

#include <TApplication.h>
#include <TVirtualFitter.h>

int main(int argc, char** argv) {
  TApplication application("analysis", &argc, argv);
  //TH1::AddDirectory(false);
  Helpers::setRootStyle();

  QFile textFile("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/light_1.csv");
  int count=0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          count++;
          stream.readLine();
      }
  } else {
      qDebug() << "cannot open file !!";
      return 0;
  }
  textFile.close();

  const int nFibres = count;
  TGraph* gl0 = new TGraph(nFibres);
  TGraph* gl1 = new TGraph(nFibres);
  TGraph* gl2 = new TGraph(nFibres);
  TGraph* gl3 = new TGraph(nFibres);
  TGraph* gd0 = new TGraph(nFibres);
  TGraph* gd1 = new TGraph(nFibres);
  TGraph* gd2 = new TGraph(nFibres);
  TGraph* gd3 = new TGraph(nFibres);


  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gl0->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/light_2.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gl1->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/light_3.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gl2->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/light_4.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gl3->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/dark_1.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gd0->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/dark_2.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gd1->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/dark_3.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gd2->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00816/reproducibility_scan/dark_4.csv");
  count = 0;
  if (textFile.open(QIODevice::ReadOnly)) {
      QTextStream stream(&textFile);
      while (!stream.atEnd())
      {
          coordinate fibre;
          double dump;
          stream >> fibre.number >> dump
                    >> fibre.x >> fibre.y;
          //qDebug() << "shortFiber" << fibre.number << fibre.x << fibre.y;
          if (fibre.number != (count+1))
              qDebug() << "fibre " << count << " skipped!";
          gd3->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  /* draw and fit */

  TCanvas* c1 = new TCanvas("c1", "c1");
  c1->cd();
  gl0->GetXaxis()->SetTitle("x [mm]");
  gl0->GetYaxis()->SetTitle("y [#mum]");
  gl0->GetXaxis()->SetTitleOffset(1.25);
  gl0->GetXaxis()->SetTitleSize(25);
  gl0->GetYaxis()->SetTitleOffset(1.15);
  gl0->GetYaxis()->SetTitleSize(25);
  gl0->SetMarkerStyle(8);
  gl0->SetMarkerSize(0.5);
  gl0->SetTitle("");
  //gl0->GetYaxis()->SetRangeUser(8.,26.);
  //gl0->GetXaxis()->SetLimits(0.,230.);
  gl0->SetMarkerColor(kBlue);
  gl0->Draw("ap");

  gl1->SetMarkerStyle(8);
  gl1->SetMarkerSize(0.5);
  gl1->SetMarkerColor(kBlue);
  gl1->Draw("p same");

  gl2->SetMarkerStyle(8);
  gl2->SetMarkerSize(0.5);
  gl2->SetMarkerColor(kBlue);
  gl2->Draw("p same");

  gl3->SetMarkerStyle(8);
  gl3->SetMarkerSize(0.5);
  gl3->SetMarkerColor(kBlue);
  gl3->Draw("p same");

  gd0->SetMarkerStyle(8);
  gd0->SetMarkerSize(0.5);
  gd0->SetMarkerColor(kBlack);
  gd0->Draw("p same");

  gd1->SetMarkerStyle(8);
  gd1->SetMarkerSize(0.5);
  gd1->SetMarkerColor(kBlack);
  gd1->Draw("p same");

  gd2->SetMarkerStyle(8);
  gd2->SetMarkerSize(0.5);
  gd2->SetMarkerColor(kBlack);
  gd2->Draw("p same");

  gd3->SetMarkerStyle(8);
  gd3->SetMarkerSize(0.5);
  gd3->SetMarkerColor(kBlack);
  gd3->Draw("p same");

  /*
  TLegend* l1 = new TLegend(.8,.8,.9,.9);
  l1->AddEntry(gs ,"connection piece", "p");
  l1->AddEntry(gl ,"fiber mat ", "p");
  l1->Draw("SAME");
  */

  application.Run();
  return 0;
}
