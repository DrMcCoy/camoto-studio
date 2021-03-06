/**
 * @file   gamelist.hpp
 * @brief  Interface to the list of supported games.
 *
 * Copyright (C) 2010-2015 Adam Nielsen <malvineous@shikadi.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GAMELIST_HPP_
#define _GAMELIST_HPP_

#include <boost/shared_ptr.hpp>
#include <wx/wx.h>
#include <vector>
#include <map>
#include <camoto/suppitem.hpp>
#include <camoto/gamegraphics/tileset.hpp>
#include <camoto/gamemaps/map.hpp>

/// Minor type for an archive where the file offsets are listed in the XML
#define ARCHTYPE_MINOR_FIXED "fixed"

/// Minor type for a tileset where the tile positions within an image are
/// listed in the XML
#define TILESETTYPE_MINOR_FROMSPLIT "_split"

/// Minor type for a tileset where the tiles are images listed in the XML
#define TILESETTYPE_MINOR_FROMIMG "_img"

/// A basic tree implementation for storing the game item structure
template <typename T>
struct tree
{
	tree() throw () { };
	tree(const T& item) throw () : item(item) { };
	T item;
	typedef std::vector< tree<T> > children_t;
	children_t children;
};

/// SuppItem -> game object ID mapping.
typedef std::map<camoto::SuppItem::Type, wxString> SuppIDs;

/// Types of dependent objects.
/**
 * Dependent objects are full blown object instances (like a TilesetPtr) that
 * are required by other objects (like a map needing a tileset.)  Unlike
 * supplementary items, which are just streams, dependent objects are full
 * instances of specific Camoto types.
 */
enum DepType
{
	GenericTileset1    = 0 + camoto::gamemaps::GenericTileset1,
	GenericTileset2    = 0 + camoto::gamemaps::GenericTileset2,
	GenericTileset3    = 0 + camoto::gamemaps::GenericTileset3,
	GenericTileset4    = 0 + camoto::gamemaps::GenericTileset4,
	GenericTileset5    = 0 + camoto::gamemaps::GenericTileset5,
	GenericTileset6    = 0 + camoto::gamemaps::GenericTileset6,
	GenericTileset7    = 0 + camoto::gamemaps::GenericTileset7,
	GenericTileset8    = 0 + camoto::gamemaps::GenericTileset8,
	GenericTileset9    = 0 + camoto::gamemaps::GenericTileset9,
	BackgroundTileset1 = 0 + camoto::gamemaps::BackgroundTileset1,
	BackgroundTileset2 = 0 + camoto::gamemaps::BackgroundTileset2,
	BackgroundTileset3 = 0 + camoto::gamemaps::BackgroundTileset3,
	BackgroundTileset4 = 0 + camoto::gamemaps::BackgroundTileset4,
	BackgroundTileset5 = 0 + camoto::gamemaps::BackgroundTileset5,
	BackgroundTileset6 = 0 + camoto::gamemaps::BackgroundTileset6,
	BackgroundTileset7 = 0 + camoto::gamemaps::BackgroundTileset7,
	BackgroundTileset8 = 0 + camoto::gamemaps::BackgroundTileset8,
	BackgroundTileset9 = 0 + camoto::gamemaps::BackgroundTileset9,
	ForegroundTileset1 = 0 + camoto::gamemaps::ForegroundTileset1,
	ForegroundTileset2 = 0 + camoto::gamemaps::ForegroundTileset2,
	ForegroundTileset3 = 0 + camoto::gamemaps::ForegroundTileset3,
	ForegroundTileset4 = 0 + camoto::gamemaps::ForegroundTileset4,
	ForegroundTileset5 = 0 + camoto::gamemaps::ForegroundTileset5,
	ForegroundTileset6 = 0 + camoto::gamemaps::ForegroundTileset6,
	ForegroundTileset7 = 0 + camoto::gamemaps::ForegroundTileset7,
	ForegroundTileset8 = 0 + camoto::gamemaps::ForegroundTileset8,
	ForegroundTileset9 = 0 + camoto::gamemaps::ForegroundTileset9,
	SpriteTileset1     = 0 + camoto::gamemaps::SpriteTileset1,
	SpriteTileset2     = 0 + camoto::gamemaps::SpriteTileset2,
	SpriteTileset3     = 0 + camoto::gamemaps::SpriteTileset3,
	SpriteTileset4     = 0 + camoto::gamemaps::SpriteTileset4,
	SpriteTileset5     = 0 + camoto::gamemaps::SpriteTileset5,
	SpriteTileset6     = 0 + camoto::gamemaps::SpriteTileset6,
	SpriteTileset7     = 0 + camoto::gamemaps::SpriteTileset7,
	SpriteTileset8     = 0 + camoto::gamemaps::SpriteTileset8,
	SpriteTileset9     = 0 + camoto::gamemaps::SpriteTileset9,
	FontTileset1       = 0 + camoto::gamemaps::FontTileset1,
	FontTileset2       = 0 + camoto::gamemaps::FontTileset2,
	FontTileset3       = 0 + camoto::gamemaps::FontTileset3,
	FontTileset4       = 0 + camoto::gamemaps::FontTileset4,
	FontTileset5       = 0 + camoto::gamemaps::FontTileset5,
	FontTileset6       = 0 + camoto::gamemaps::FontTileset6,
	FontTileset7       = 0 + camoto::gamemaps::FontTileset7,
	FontTileset8       = 0 + camoto::gamemaps::FontTileset8,
	FontTileset9       = 0 + camoto::gamemaps::FontTileset9,
	BackgroundImage    = 0 + camoto::gamemaps::BackgroundImage,
	Palette,
	DepTypeCount // must always be last
};

/// Convert a DepType value into a string, for error messages.
wxString dep2string(DepType t);

/// Dependency type -> game object ID mapping.
typedef std::map<DepType, wxString> Deps;

/// Details about a single game object, such as a map or a song.
struct GameObject
{
	inline virtual ~GameObject() {};

	wxString id;           ///< Unique ID for this object
	wxString filename;     ///< Object's filename
	wxString idParent;     ///< ID of containing object, or empty for local file
	wxString typeMajor;    ///< Major type (editor to use)
	wxString typeMinor;    ///< Minor type (file format)
	wxString filter;       ///< Decompression/decryption filter ID, blank for none
	wxString friendlyName; ///< Name to show user
	SuppIDs supp;          ///< SuppItem -> id mapping
	Deps dep;              ///< Which objects this one is dependent upon

	int offset;            ///< [Fixed archive only] Offset of this file
	int size;              ///< [Fixed archive only] Size of this file
};

/// Shared pointer to a GameObject
typedef boost::shared_ptr<GameObject> GameObjectPtr;

/// Map between id and game object
typedef std::map<wxString, GameObjectPtr> GameObjectMap;

/// Structure of a tileset defined directly in the XML, where the content is
/// from an image split into parts
struct TilesetFromSplitInfo
{
	wxString id;           ///< Unique ID for this object
	wxString idImage;      ///< ID of the underlying image to split into tiles
	unsigned int layoutWidth; ///< Ideal width of the tileset, in number of tiles
	camoto::gamegraphics::TileList tileList; ///< List of tile coordinates in the parent image
};

/// Map of tileset IDs to tileset data
typedef std::map<wxString, TilesetFromSplitInfo> TilesetsFromSplit;

/// Structure of a tileset defined directly in the XML, where the content is
/// from multiple images
struct TilesetFromImagesInfo
{
	wxString id;                       ///< Unique ID for this object
	unsigned int layoutWidth;          ///< Ideal width of the tileset, in number of tiles
	std::vector<std::string> ids;      ///< List of IDs for each tile
	std::vector<std::string> names;    ///< List of names for each tile
};

/// Map of tileset IDs to tileset data
typedef std::map<wxString, TilesetFromImagesInfo> TilesetsFromImages;

/// Game details for the UI
struct GameInfo
{
	wxString id;        ///< Game ID, used for resource filenames
	wxString title;     ///< User-visible title
	wxString developer; ///< Game dev
	wxString reverser;  ///< Who reverse engineered the file formats
};

/// Object descriptions for map editor
struct MapObject
{
	/// Run of tile codes
	typedef std::vector<unsigned int> TileRun;

	/// A row of tiles in the object.
	/**
	 * Each row (going left-to-right) starts with one or more "left" tiles,
	 * followed by one or more "mid" tiles.  The mid tile list is repeated
	 * as necessary to fill up the available space.  The row then finishes
	 * with one or more "right" tiles.
	 */
	struct Row {

		/// Array indices for segment.
		enum DirX {
			L = 0,      ///< Tiles on the left
			M = 1,      ///< Tiles in the middle, repeated
			R = 2,      ///< Tiles on the right
			Count = 3,  ///< Number of elements for array sizes
		};

		/// Actual tile runs.  Array index is a DirX value.
		TileRun segment[Count];
	};

	typedef std::vector<Row> RowVector;

	/// User-visible name of this object for tooltips, etc.
	wxString name;

	/// Minimum width for this object in tiles, or zero for no minimum.
	unsigned int minWidth;

	/// Minimum height for this object in tiles, or zero for no minimum.
	unsigned int minHeight;

	/// Maximum width for this object in tiles, or zero for no maximum.
	unsigned int maxWidth;

	/// Maximum height for this object in tiles, or zero for no maximum.
	unsigned int maxHeight;

	/// Array indices for section.
	enum DirY {
		TopSection = 0,    ///< Rows at the top of the object
		MidSection = 1,    ///< Rows in the middle of the object, repeated
		BotSection = 2,    ///< Rows at the bottom of the object
		SectionCount = 3,  ///< Number of elements for array sizes
	};

	/// List of rows for each section (top/middle/bottom).  Index is a DirY value.
	RowVector section[SectionCount];
};

typedef std::vector<MapObject> MapObjectVector;

/// All data about a game that can be edited.
struct Game: public GameInfo
{
	GameObjectMap objects;
	TilesetsFromSplit tilesetsFromSplit;
	TilesetsFromImages tilesetsFromImages;
	tree<wxString> treeItems;
	MapObjectVector mapObjects;
	std::map<wxString, wxString> dosCommands;

	/// Find an object by filename.
	GameObjectPtr findObjectByFilename(const wxString& filename,
		const wxString& typeMajor);

	/// Find an object by its ID.
	/**
	 * This must be used instead of the array operator[], as this function
	 * won't create an empty entry when checking for an invalid ID, causing
	 * the ID to subsequently become valid.
	 */
	GameObjectPtr findObjectById(const wxString& id);
};

/// List of basic game info.
typedef std::map<wxString, GameInfo> GameInfoMap;

/// Load a list of games from the XML files in the given location.
/**
 * @return List of all supported games.
 */
GameInfoMap getAllGames();

/// Load a single game's data from the XML files in the given location.
/**
 * @param id
 *   ID of the game.
 *
 * @return Game instance containing information about the given game, or
 *   NULL on error.
 */
Game *loadGameStructure(const wxString& id);

#endif // _GAMELIST_HPP_
