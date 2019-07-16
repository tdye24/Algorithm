package ͼ;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class Dijkstra {

	public static void main(String[] args) {
		Graph g = new Graph();
		g.addVertex('1', Arrays.asList(new Vertex('6', 100), new Vertex('3', 10), new Vertex('5', 30)));
		g.addVertex('2', Arrays.asList(new Vertex('3', 5)));
		g.addVertex('3', Arrays.asList(new Vertex('4', 50)));
		g.addVertex('4', Arrays.asList(new Vertex('6', 10)));
		g.addVertex('5', Arrays.asList(new Vertex('6', 60), new Vertex('4', 20)));
		g.addVertex('6', Arrays.asList());
		System.out.println(g.getShortestPath('1'));
	}

}

class Vertex implements Comparable<Vertex> {
	private Character id;
	private Integer distance;
	
	public Vertex(Character id, Integer distance) {
		this.id = id;
		this.distance = distance;
	}
	
	public Character getId() {
		return id;
	}

	public Integer getDistance() {
		return distance;
	}

	public void setId(Character id) {
		this.id = id;
	}

	public void setDistance(Integer distance) {
		this.distance = distance;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((distance == null) ? 0 : distance.hashCode());
		result = prime * result + ((id == null) ? 0 : id.hashCode());
		return result;
	}

	@Override
	public int compareTo(Vertex o) {
		if (this.distance < o.distance)
			return -1;
		else if (this.distance > o.distance)
			return 1;
		else
			return this.getId().compareTo(o.getId());
	}
	
}

class Graph {
	private final HashMap<Character, List<Vertex>> vertexs;
	
	public Graph() {
		this.vertexs = new HashMap<Character, List<Vertex>>();
	}
	
	public void addVertex(Character character, List<Vertex> vertex) {
		this.vertexs.put(character, vertex);
	}
	
	public Map<Character, Integer> getShortestPath(Character start) {
		final Map<Character, Integer> distances = new HashMap<Character, Integer>();
		final Map<Character, Integer> nodes = new HashMap<Character, Integer>();
		
		for(Character vertex:this.vertexs.keySet()) {
			if(vertex == start) {
				nodes.put(start, 0);
			} else {
				distances.put(vertex, Integer.MAX_VALUE);
			}
		}
		int shortest;
		
		Character extendedVertexId = start;
		
		while(nodes.size() != this.vertexs.size()) {
			for(Vertex vertex: this.vertexs.get(extendedVertexId)) {
				if(nodes.containsKey(vertex.getId())) {
					continue;
				}
				shortest = nodes.get(extendedVertexId) + vertex.getDistance();
				if(shortest < distances.get(vertex.getId())) {
					distances.replace(vertex.getId(), shortest);
				}
			}
			
			
			Vertex smallvertex = new Vertex(' ', Integer.MAX_VALUE);
			for(Character id: distances.keySet()) {
				if(distances.get(id) < smallvertex.getDistance()) {
					smallvertex.setId(id);
					smallvertex.setDistance(distances.get(id));
				}
			}
			if(smallvertex.getId() == ' ') {
				for(Character id: distances.keySet()) {
					nodes.put(id, Integer.MAX_VALUE);
				}
				break;
			}
			nodes.put(smallvertex.getId(), smallvertex.getDistance());
			distances.remove(smallvertex.getId());
			extendedVertexId = smallvertex.getId();
		}
		return nodes;
	}
}
