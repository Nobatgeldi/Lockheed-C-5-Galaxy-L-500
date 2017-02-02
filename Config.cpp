
//Rework and Upgrade By N.G
#include "CfgPatches.hpp"
#include "CfgSounds.hpp"
#include "CfgRadio.hpp"
#include "CfgMovesBasic.hpp"
// some basic defines
#define TEast 0
#define TWest 1
#define TGuerrila 2
#define TCivilian 3
#define TSideUnknown 4
#define TEnemy 5
#define TFriendly 6
#define TLogic 7

#define true 1
#define false 0

// type scope
#define private 0
#define protected 1
#define public 2

class CfgVehicles
{
	class All {};
	class AllVehicles: All {};
	class Air: AllVehicles {};
	class Plane: Air
	{
		class HitPoints;
		class AnimationSources;
		class NewTurret;
		class ViewPilot;
    };
	class galaxy_c5: Plane
	{
		scope=public;
		brakeDistance=400;
		faction="BLU_F";
		mapSize = 78;
		crew = "B_Helipilot_F";
		icon="\galaxy_c5\icons\icon.paa";
		picture="\galaxy_c5\icons\picture.paa";
		side=TWest;
		simulation="airplane";
		_generalMacro="Plane";
		displayName="$STR_GALAXY_C5_NAME1";
		accuracy=0.90;
		irTarget=1;
		irScanRange=3000;
		irScanGround=0;
    maxSpeed = 920;
		soundEngine[]={"\galaxy_c5\sound\X_b_JT8D_2.wav",4,1.2};
		soundLandCrash[] = {"\galaxy_c5\sound\touchr.wav", 5, 0.5, 700};
		soundEnviron[]={"sounds_f\air\Plane_Fighter_03\noise",db-60,1.0};
		soundServo[]={"\galaxy_c5\sound\FLAPS.WAV",4,1.2};
		soundGear[] = {"\galaxy_c5\sound\geardn.wav",4,1.2}; //no default'
		soundEngineOnInt[] = {"\galaxy_c5\sound\T_COMB_START.wav", 0.562341, 1.000000};
		soundEngineOnExt[] = {"\galaxy_c5\sound\T_COMB_START.wav", 1.0, 1.000000, 900};
		soundEngineOffInt[] = {"\galaxy_c5\sound\X_T_JT8D_SHUT.wav", 0.562341, 1.000000};
		soundEngineOffExt[] = {"\galaxy_c5\sound\X_T_JT8D_SHUT.wav", 1.0, 1.000000, 900};
		soundFlapsUp[]=
		{
			"A3\Sounds_F_EPC\CAS_02\Flaps_Up",
			0.63095701,
			1,
			100
		};
		soundFlapsDown[]=
		{
			"A3\Sounds_F_EPC\CAS_02\Flaps_Down",
			0.63095701,
			1,
			100
		};
		soundGearUp[]=
		{
			"A3\Sounds_F_EPC\CAS_02\gear_up",
			0.79432797,
			1,
			150
		};
		soundGearDown[]=
		{
			"A3\Sounds_F_EPC\CAS_02\gear_down",
			0.79432797,
			1,
			150
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[]=
				{
					"\il76td\sounds\engine_in",
					2.5118899,
					1,
					1600
				};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineLowIn
			{
				sound[]=
				{
					"\il76td\sounds\engine_in",
					1.2589254,
					1
				};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"\il76td\sounds\engine_in",
					2.5118899,
					1.3,
					1800
				};
				frequency = "1";
				volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};
			class EngineHighIn
			{
				sound[]=
				{
					"\il76td\sounds\engine_in",
					2.2589254,
					1
				};
				frequency = "1";
				volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
			};
			class ForsageOut
			{
				sound[]=
				{
					"\il76td\sounds\ext-jetair-forsage1",
					//"\il76td\sounds\engine_in",
					2.0,
					1.1,
					2000
				};
				frequency="1";
				volume="engineOn*camPos*(thrust factor[0.5, 1.0])";
				cone[]={3.1400001,3.9200001,2,0.30000001};
			};
			class ForsageIn
			{
				sound[]=
				{
					"\il76td\sounds\engine_in",
					1.4125376,
					1.2
				};
				frequency="0.5 + engineOn*(speed factor[1,150]))";
				volume="(1-camPos)*(engineOn*(thrust factor[0.75, 1.0]))";
			};
			class WindNoiseOut
			{
				sound[]=
				{
					"\il76td\sounds\ext-jetair-wind",
					5,
					1,
					500
				};
				frequency="(0.1+(1.2*(speed factor[1, 150])))";
				volume="camPos*(speed factor[1, 150])";
			};
			class WindNoiseIn
			{
				sound[]=
				{
					"\il76td\sounds\int-jetair-wind1",
					0.44668359,
					1.1
				};
				frequency="(0.1+(1.2*(speed factor[1, 150])))";
				volume="(1-camPos)*(speed factor[1, 150])";
			};
			class DistantPlaneOut
			{
				sound[]=
				{
					"\il76td\sounds\distantplane",
					4,
					0.5,
					5000
				};
				frequency="1";
				volume="engineOn*camPos*(speed factor[1, 100])";
				cone[]={3.1400001,3.9200001,2,0.2};
			};
		};
		armor=250;
		cost=2000000;
		transportSoldier=0;
		model="\galaxy_c5\galaxy_c5";
		/*aileronSensitivity = 1.4;
		elevatorSensitivity = 3.7; */
		aileronSensitivity = 0.6;
		elevatorSensitivity = 3.7; // relative elevator sensitivity
		noseDownCoef = 1.1; // how much goes nose down during turns
		wheelSteeringSensitivity = 8.5;

		landingAoa = "rad 5"//7*3.1415/180//"rad 55";
		envelope[] = {0.000000, 0.100000, 0.800000, 2.000000, 2.200000, 2.800000, 3.550000, 3.550000, 3.550000, 3.550000, 2.600000, 0.800000, 1.000000};
    landingSpeed = 225;
		gearRetracting = True;
		ejectSpeed[]={0,0,0};
		extCameraPosition[]={0,8,-75};
		type=VAir;
		//threat[] VSoft, VArmor, VAir
		threat[]={0.1, 1, 0.7};
    animated=1;
		hiddenSelections[]={"num"};
		transportFuel = 100000;
		transportVehiclesCount = 4;
		transportVehiclesMass = 2000000;
		getInRadius=1.5;
		vehicleClass = "Air";
		driverAction = "pilot";
		gunnerAction = "gunner";
		cargoAction[] =
		{
			"passenger_generic01_leanleft",
			"passenger_generic01_foldhands",
			"passenger_generic01_leanright",
			"passenger_generic01_leanleft",
			"passenger_generic01_leanright",
			"passenger_generic01_leanleft",
			"passenger_generic01_foldhands",
			"passenger_generic01_leanleft"
		};
		insideSoundCoef=0.15000;
		hascommander=0;
		hasGunner=1;
		weapons[]=
		{
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine"
		};

		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};

		class Library {
			libTextDesc = "$STR_GALAXY_C5_DESCR";
		};

		class ViewPilot : ViewPilot
		{
			initFov = 0.8; minFov = 0.3; maxFov = 1.2;
			initAngleX = 0; minAngleX = -40; maxAngleX = +100;
			initAngleY = 0; minAngleY = -180; maxAngleY = 180;
		};

		class AnimationSources : AnimationSources
		{
			class nose_ramp
			{
				source = "user";
				initPhase = 0;
				animPeriod = 20;
			};

			class back_ramp
			{
				source = "user";
				initPhase = 0;
				animPeriod = 20;
			};
		};

		class Turrets
		{
			class MainTurret : NewTurret
			{
				body = "";
				gun = "";
				commanding = -1;
				proxyIndex = 1;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				weapons[]={};
				magazines[]={};
				castGunnerShadow = true;
				viewGunnerShadow = true;
				gunnerAction = "pilot";
				gunnerInAction = "pilot";
				gunnerName="$STR_WOP_PILOT2_NAME";
			};

			class Ing1 : MainTurret {
				body = "";
				gun = "";
				commanding = -1;
				proxyIndex = 2;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				weapons[]={};
				magazines[]={};
				castGunnerShadow = true;
				viewGunnerShadow = true;
				gunnerAction = "Truck_Cargo01";
				gunnerInAction = "Truck_Cargo01";
				gunnerName="$STR_WOP_PILOT3_NAME";
				primaryGunner = 0;
			};
			class Ing2 : MainTurret {
				body = "";
				gun = "";
				commanding = -1;
				proxyIndex = 3;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				weapons[]={};
				magazines[]={};
				castGunnerShadow = true;
				viewGunnerShadow = true;
				gunnerAction = "Truck_Cargo02";
				gunnerInAction = "Truck_Cargo02";
				gunnerName="$STR_WOP_PILOT4_NAME";
				primaryGunner = 0;
			};
			class Ing3 : MainTurret {
				body = "";
				gun = "";
				commanding = -1;
				proxyIndex = 4;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				weapons[]={};
				magazines[]={};
				castGunnerShadow = true;
				viewGunnerShadow = true;
				gunnerAction = "Truck_Cargo01";
				gunnerInAction = "Truck_Cargo01";
				gunnerName="$STR_WOP_PILOT5_NAME";
				primaryGunner = 0;
			};
		};

		class EventHandlers
		{
			init = "[_this select 0] exec ""\galaxy_c5\scr\init.sqs""; [_this select 0] exec ""\galaxy_c5\scr\common_init.sqs"";";
			//engine = "_this execVM ""\galaxy_c5\scr\engineon.sqf""";
		};

		class UserActions
		{
      class OpenRear
			{
				displayName="$STR_GALAXY_C5_OR";
				onlyforplayer = false;
				position="pos nose open";
				radius=100;
				showWindow = 0;
				condition="this animationPhase ""back_ramp"" == 0";
				statement = "[this] execVM ""\galaxy_c5\scr\back_rampdown.sqf""";
			};
			class CloseRear
			{
				onlyforplayer = false;
				displayName="$STR_GALAXY_C5_CR";
				position="pos nose open";
				radius=100;
				showWindow = 0;
				condition="this animationPhase ""back_ramp"" == 1";
				statement = "[this] execVM ""\galaxy_c5\scr\back_rampclose.sqf""";
			};

			class OpenNose
			{
				onlyforplayer = false;
				displayName="$STR_GALAXY_C5_ON";
				position="pos nose open";
				radius=100;
				showWindow = 0;
				condition="this animationPhase ""nose_ramp"" == 0 and !isengineon this";
				statement = "[this] execVM ""\galaxy_c5\scr\nose_rampdown.sqf""";
			};
			class CloseNose
			{
				onlyforplayer = false;
				displayName="$STR_GALAXY_C5_CN";
				position="pos nose open";
				radius=100;
				showWindow = 0;
				condition="this animationPhase ""nose_ramp"" == 1 and !isengineon this";
				statement = "[this] execVM ""\galaxy_c5\scr\nose_rampclose.sqf""";
			};

      /*class parasoldiers
			{
				onlyforplayer = false;
				displayName="$STR_galaxy_c5_PS";
				position="pos nose open";
				radius=100;
				showWindow = 0;
				condition = "(player in this) and (count crew (vehicle this) > 2) and (getpos this select 2 > 100)";
				statement="[this, player] execVM ""\galaxy_c5\scr\paragroup.sqf""";
			};
			class paracargo
			{
				onlyforplayer = false;
				displayName = "$STR_galaxy_c5_PC";
				position="pos nose open";
				radius=100;
				showWindow = 0;
				condition = "getpos this select 2 > 7 and (this animationPhase ""cargoload"" > 0)";
				statement="[this] exec ""\galaxy_c5\scr\galaxy_c5paracargo.sqs"",this animate [""relase"",1]";
			};*/

			class loadcargo
			{
				onlyforplayer = false;
				displayName = "$STR_GALAXY_C5_LC";
				position="axiscargo";
				radius=20;
				showWindow = 0;
				condition = "((vehicle player != vehicle this) and (vehicle player != player) and (speed vehicle this < 5))";
				statement = "[this, vehicle player, player] execVM ""\galaxy_c5\scr\attach.sqf""";
			};

			class unloadcargo
			{
				onlyforplayer = false;
				displayName = "$STR_GALAXY_C5_UC";
				position="axiscargo";
				radius=100;
				showWindow = 0;
				condition = "(vehicle player != vehicle this) and (vehicle player != player)";
				statement = "[this, vehicle player, player] execVM ""\galaxy_c5\scr\detach.sqf""";
			};

			class unloadcargoall
			{
				onlyforplayer = false;
				displayName = "$STR_GALAXY_C5_UCA";
				position="axiscargo";
				radius=100;
				showWindow = 0;
				//condition = "(player in this) and ((count (position this nearEntities 30)) > 1)";
				condition = "(player in this) and ((count (position this nearEntities 30)) > 1) and (this animationPhase ""RearDoor""< 0.5)";
				statement = "[this, vehicle player, player] execVM ""\galaxy_c5\scr\detachall.sqf""";
			};

      /*class paraSuport
			{
				displayName = "$STR_galaxy_c5_PARA";
				position="pos nose open";
				onlyforplayer = false;
				radius=100;
				condition="! (isengineon this) && player distance this <5 && this animationphase ""cargoswitch"" ==0 && this animationphase ""cargoswitch2"" ==0";
				statement = "[this,player] exec ""\galaxy_c5\Cargo\galaxy_c5groupbail.sqs"";player groupchat ""Plane being Drop suport by parachute!""";
			};*/
		};

		class MarkerLights
		{
			class RedStill
			{
				color[]={1000,0,0,1};
				ambient[]={1,0,0,1};
				name = "cerveny pozicni";
				brightness = 0.15;
				blinking = false;
			};

			class GreenStill
			{
				color[]={0.029999999,1,0.11,1};
				ambient[]={100,100,100,0};
				name = "zeleny pozicni";
				brightness = 0.15;
				blinking = false;
			};

			class WhiteStill
			{
				color[]={1,1,1,1};
				ambient[]={1,1,1,1};
				name = "bily pozicni";
				brightness = 0.15;
				blinking = false;
			};

			class WhiteBlinking
			{
				color[]={1,1,1,1};
				ambient[]={1,1,1,1};
				name = "bily pozicni blik";
				brightness = 0.15;
				blinking = true;
			};

			class RedBlinking
			{
				color[]={1000,0,0,1};
				ambient[]={1,0,0,1};
				name = "cerveny pozicni blik";
				brightness = 0.15;
				blinking = true;
			};

			class BlueStill
			{
				color[]={0.029999999,1,0.11,1};
				ambient[]={100,100,100,0};
				name = "blue";
				brightness = 0.15;
				blinking = false;
			};
		};

		class Reflectors
		{
			class Left
			{
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				position="L svetlo";
				direction="konec L svetla";
				hitpoint="L svetlo";
				selection="L svetlo";
				size=1;
				innerAngle=20;
				outerAngle=60;
				coneFadeCoef=10;
				intensity=50;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				brightness=1;
				class Attenuation
				{
					constant=0;
					hardlimitend=250;
					hardlimitstart=200;
					linear=1;
					quadratic=0;
					start=0;
				};
			};
			class Right
			{
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 1;
				innerAngle=20;
				outerAngle=60;
				coneFadeCoef=10;
				intensity=25;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
				};
			};

			class Left2
			{
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				position = "L svetlo2";
				direction = "konec L svetla2";
				hitpoint = "L svetlo2";
				selection = "L svetlo2";
				size=1;
				innerAngle=20;
				outerAngle=60;
				coneFadeCoef=10;
				intensity=50;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				brightness=1;
				class Attenuation
				{
					constant=0;
					hardlimitend=250;
					hardlimitstart=200;
					linear=1;
					quadratic=0;
					start=0;
				};
			};

			class Right2
			{
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				position = "P svetlo2";
				direction = "konec P svetla2";
				hitpoint = "P svetlo2";
				selection = "P svetlo2";
				size=1;
				innerAngle=20;
				outerAngle=60;
				coneFadeCoef=10;
				intensity=50;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				brightness=1;
				class Attenuation
				{
					constant=0;
					hardlimitend=250;
					hardlimitstart=200;
					linear=1;
					quadratic=0;
					start=0;
				};
			};
		};

		class Exhausts
		{
		   class Exhaust1
		   {
			   position = "exhaust1";
			   direction = "exhaust1_dir";
			   effect = "ExhaustsEffectPlane";
		   };

		   class Exhaust2
		   {
			   position = "exhaust2";
			   direction = "exhaust2_dir";
			   effect = "ExhaustsEffectPlane";
		   };

		   class Exhaust3
		   {
			   position = "exhaust3";
			   direction = "exhaust3_dir";
			   effect = "ExhaustsEffectPlane";
		   };

		   class Exhaust4
		   {
			   position = "exhaust4";
			   direction = "exhaust4_dir";
			   effect = "ExhaustsEffectPlane";
		   };
		};
	};
};
