#include <GCPnts_AbscissaPoint.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <gcpnts.h>

double CurveLength(BRepAdapterCurve c) {
    BRepAdaptor_Curve * curve = (BRepAdaptor_Curve *)c;
    return GCPnts_AbscissaPoint::Length(*curve);
}
