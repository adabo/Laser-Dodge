/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	Keyboard.h																			  *
 *	Copyright 2012 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

class KeyboardServer;

class KeyboardClient
{
public:
	KeyboardClient( const KeyboardServer& kServer );
	bool UpIsPressed() const;
	bool DownIsPressed() const;
	bool LeftIsPressed() const;
	bool RightIsPressed() const;
	bool SpaceIsPressed() const;
	bool EnterIsPressed() const;
    bool TildeIsPressed() const;
    bool AIsPressed() const;
    bool BIsPressed() const;
    bool CIsPressed() const;
    bool DIsPressed() const;
    bool EIsPressed() const;
    bool FIsPressed() const;
    bool GIsPressed() const;
    bool HIsPressed() const;
    bool IIsPressed() const;
    bool JIsPressed() const;
    bool KIsPressed() const;
    bool LIsPressed() const;
    bool MIsPressed() const;
    bool NIsPressed() const;
    bool OIsPressed() const;
    bool PIsPressed() const;
    bool QIsPressed() const;
    bool RIsPressed() const;
    bool SIsPressed() const;
    bool TIsPressed() const;
    bool UIsPressed() const;
    bool VIsPressed() const;
    bool WIsPressed() const;
    bool XIsPressed() const;
    bool YIsPressed() const;
    bool ZIsPressed() const;
private:
	const KeyboardServer& server;
};

class KeyboardServer
{
	friend KeyboardClient;
public:
	KeyboardServer();

	void OnUpPressed();
	void OnDownPressed();
	void OnLeftPressed();
	void OnRightPressed();
	void OnSpacePressed();
	void OnEnterPressed();
    void OnTildePressed();

    void OnAPressed();
    void OnBPressed();
    void OnCPressed();
    void OnDPressed();
    void OnEPressed();
    void OnFPressed();
    void OnGPressed();
    void OnHPressed();
    void OnIPressed();
    void OnJPressed();
    void OnKPressed();
    void OnLPressed();
    void OnMPressed();
    void OnNPressed();
    void OnOPressed();
    void OnPPressed();
    void OnQPressed();
    void OnRPressed();
    void OnSPressed();
    void OnTPressed();
    void OnUPressed();
    void OnVPressed();
    void OnWPressed();
    void OnXPressed();
    void OnYPressed();
    void OnZPressed();

	void OnUpReleased();
	void OnDownReleased();
	void OnLeftReleased();
	void OnRightReleased();
	void OnSpaceReleased();
	void OnEnterReleased();
    void OnTildeReleased();

    void OnAReleased();
    void OnBReleased();
    void OnCReleased();
    void OnDReleased();
    void OnEReleased();
    void OnFReleased();
    void OnGReleased();
    void OnHReleased();
    void OnIReleased();
    void OnJReleased();
    void OnKReleased();
    void OnLReleased();
    void OnMReleased();
    void OnNReleased();
    void OnOReleased();
    void OnPReleased();
    void OnQReleased();
    void OnRReleased();
    void OnSReleased();
    void OnTReleased();
    void OnUReleased();
    void OnVReleased();
    void OnWReleased();
    void OnXReleased();
    void OnYReleased();
    void OnZReleased();
private:
	bool upIsPressed;
	bool downIsPressed;
	bool leftIsPressed;
	bool rightIsPressed;
	bool spaceIsPressed;
	bool enterIsPressed;
    bool tilde_is_pressed;
    bool a_is_pressed;
    bool b_is_pressed;
    bool c_is_pressed;
    bool d_is_pressed;
    bool e_is_pressed;
    bool f_is_pressed;
    bool g_is_pressed;
    bool h_is_pressed;
    bool i_is_pressed;
    bool j_is_pressed;
    bool k_is_pressed;
    bool l_is_pressed;
    bool m_is_pressed;
    bool n_is_pressed;
    bool o_is_pressed;
    bool p_is_pressed;
    bool q_is_pressed;
    bool r_is_pressed;
    bool s_is_pressed;
    bool t_is_pressed;
    bool u_is_pressed;
    bool v_is_pressed;
    bool w_is_pressed;
    bool x_is_pressed;
    bool y_is_pressed;
    bool z_is_pressed;
};