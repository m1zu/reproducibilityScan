#include "Helpers.hh"
#include "coordinate.hh"

#include <TApplication.h>
#include <TVirtualFitter.h>

int main(int argc, char** argv) {
  TApplication application("analysis", &argc, argv);
  //TH1::AddDirectory(false);
  Helpers::setRootStyle();

  QFile textFile("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00127/reproducibility_scan/1.csv");
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
  TGraph* g0 = new TGraph(nFibres);
  TGraph* g1 = new TGraph(nFibres);
  TGraph* g2 = new TGraph(nFibres);
  TGraph* g3 = new TGraph(nFibres);
  TGraph* g4 = new TGraph(nFibres);

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
          g0->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00127/reproducibility_scan/2.csv");
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
          g1->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00127/reproducibility_scan/3.csv");
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
          g2->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00127/reproducibility_scan/4.csv");
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
          g3->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  textFile.setFileName("/home/iwanicki/sw/opticalCon/data/4TSAACFIM00127/reproducibility_scan/5.csv");
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
          g4->SetPoint(fibre.number-1, (fibre.x*0.001), (fibre.y+4800.));
          count++;
          stream.readLine();
      }
  }
  textFile.close();

  /* draw and fit */

  TCanvas* c1 = new TCanvas("c1", "c1");
  c1->cd();
  g0->GetXaxis()->SetTitle("x [mm]");
  g0->GetYaxis()->SetTitle("y [#mum]");
  g0->GetXaxis()->SetTitleOffset(1.25);
  g0->GetXaxis()->SetTitleSize(25);
  g0->GetYaxis()->SetTitleOffset(1.15);
  g0->GetYaxis()->SetTitleSize(25);
  g0->SetMarkerStyle(8);
  g0->SetMarkerSize(0.5);
  g0->SetTitle("");
  //g0->GetYaxis()->SetRangeUser(8.,26.);
  //g0->GetXaxis()->SetLimits(0.,230.);
  g0->Draw("ap");

  g1->SetMarkerStyle(8);
  g1->SetMarkerSize(0.5);
  g1->SetMarkerColor(kBlue);
  g1->Draw("p same");

  g2->SetMarkerStyle(8);
  g2->SetMarkerSize(0.5);
  g2->SetMarkerColor(kRed);
  g2->Draw("p same");

  g3->SetMarkerStyle(8);
  g3->SetMarkerSize(0.5);
  g3->SetMarkerColor(kYellow);
  g3->Draw("p same");

  g4->SetMarkerStyle(8);
  g4->SetMarkerSize(0.5);
  g4->SetMarkerColor(kMagenta);
  g4->Draw("p same");

  /*
  TLegend* l1 = new TLegend(.8,.8,.9,.9);
  l1->AddEntry(gs ,"connection piece", "p");
  l1->AddEntry(gl ,"fiber mat ", "p");
  l1->Draw("SAME");
  */

  application.Run();
  return 0;
}
