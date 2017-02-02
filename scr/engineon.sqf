_tu22pp = _this select 0;
if (isengineon _tu22pp) then
{
	_tu22pp setobjecttexture[0, "\tu22pp\txt\ab1.paa"];
	sleep(6);
	_tu22pp setobjecttexture[0, "\tu22pp\txt\ab2.paa"];
	sleep(6);
	_tu22pp setobjecttexture[0, "\tu22pp\txt\ab3.paa"];
}
else
{
	_tu22pp setobjecttexture[0, ""];
};