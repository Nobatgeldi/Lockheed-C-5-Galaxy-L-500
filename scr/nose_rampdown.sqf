_galaxy_c5 = _this select 0;
if ((fuel _galaxy_c5) > 0) then
{
	galaxy_c5_fuel = fuel _galaxy_c5;
};
_galaxy_c5 setfuel 0;
_galaxy_c5 say "galaxy_c5_doors";
_galaxy_c5 animate ["nose_ramp",1];
_galaxy_c5 animate ["nose_ramp_st",1];
_galaxy_c5 animate ["nose",1];