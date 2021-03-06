#pragma once

#include "NodeAttribute.h"
#include "Mesh.h"
#include "Light.h"
#include "Material.h"
#include "NativeString.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	/// <summary>
	/// Represents a single node in the FBX scene graph.
	/// </summary>
	public ref class SceneNode
	{
	public:
		/// <summary>
		/// Gets and sets the name of this node.
		/// </summary>
		property_rw(string^, Name);
		
		/// <summary>
		/// Gets the direct children of this node.
		/// </summary>
		property_r(IEnumerable<SceneNode^>^, ChildNodes);

		/// <summary>
		/// Gets a collection of FBX attributes for this node.
		/// </summary>
		property_r(IEnumerable<NodeAttribute^>^, Attributes);

		/// <summary>
		/// Gets and sets the position of this node.
		/// </summary>
		property_rw(Vector3, Position);

		/// <summary>
		/// Gets and sets the rotation of this node.
		/// </summary>
		property_rw(Vector3, Rotation);

		/// <summary>
		/// Gets and sets the scale of this node.
		/// </summary>
		property_rw(Vector3, Scale);

		/// <summary>
		/// Gets the first mesh attribute of this node if it exists, otherwise null.
		/// </summary>
		property_r(ManagedFbx::Mesh^, Mesh);

		/// <summary>
		/// Gets the first light attribute of this node if it exists, otherwise null.
		/// </summary>
		property_r(ManagedFbx::Light^, Light);

		property_r(array<double>^, Transform);

		property_r(Vector3, GeometricTranslate);

		property_r(Vector3, GeometricRotation);

		property_r(Vector3, GeometricScale);

		/// <summary>
		/// Adds an existing node as a child of this node.
		/// </summary>
		void AddChild(SceneNode ^node);

		/// <sumary>
		/// Transform the vector by this sceneNode's Wrold Transform
		/// </sumary>
		Vector3 MultT(Vector3 vector);

		/// <sumary>
		/// Transform the vectors by this sceneNode's Wrold Transform
		/// </sumary>
		List<Vector3>^ MultT(List<Vector3>^ vectorList);


		void AddAttribute(NodeAttribute^ attribute);
		void AddMesh(ManagedFbx::Mesh^ mesh);

		List<SceneNode^>^ FindAllHierarchyChildren();
		List<Material^>^ GetAllMaterials();
		void AddMaterial(Material^ );

	internal:
		SceneNode(FbxNode *node);
		FbxNode *m_nativeNode;

	private:
		List<SceneNode^> ^m_children;
		List<NodeAttribute^> ^m_attributes;
		void SceneNode::FindChildNodes(SceneNode^ node, List<SceneNode^>^ nodeList);
	};
}