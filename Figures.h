#include "Shapes.h"
#include <vector>
#include <fstream>
#include <wx/filedlg.h>
#include <string>
#include <wx/graphics.h>

wxPoint2DDouble convert(Vector &a);

void drawpolygon(std::vector<Vector> dat, wxGraphicsContext *gc);

void fish(std::vector<Vector> &data, wxGraphicsContext *dc);

void swan(std::vector<Vector> &data, wxGraphicsContext *dc);

void horse(std::vector<Vector> &data, wxGraphicsContext *dc);

void human(std::vector<Vector> &data, wxGraphicsContext *dc);

void house(std::vector<Vector> &data, wxGraphicsContext *dc);

void boat(std::vector<Vector> &data, wxGraphicsContext *dc);