#include <iostream>

#include "useful_functions.h"



// int counter = 1;

namespace data_structures {

	namespace {

		template <typename data_> data_ absolute(data_ value) {
			return ((value < 0) ? (data_) (value * -1) : (data_) value);
		}

		template<typename data_> data_* absolute(data_* value) {
			if (*value < 0) {
				*value = (data_) (*value * -1);
			}
			return value;
		}

		template <typename data_> class node_root {

			protected:
				data_ this_data;
			
			public:

				node_root(){}

				node_root(data_ new_data) : this_data(new_data){
				}

				void set_data(data_ d) {
					this->this_data = d;
				}

				data_ get_data() const {
					return this->this_data;
				}

				data_ &get_data_ref() {
					return this->this_data;
				}

		};

		template <typename data_, typename indx_ = signed long> class numbered_node : public node_root<data_> {

			protected:
				indx_ index;

			public:

				numbered_node() {
				}

				numbered_node(data_ new_data, indx_ index = -1) : node_root<data_>(new_data) {
					this->index = index;
				}

				void set_index(indx_ index) {
					this->index = index;
				}


				indx_ get_index() const {
					return this->index;
				}

		};

		template <typename data_> class linear_node : public node_root<data_> {
			
			protected:
				linear_node<data_>* next_node;
				linear_node<data_>* previous_node;

			public:

				linear_node() {
					this->next_node = nullptr;
				}

				linear_node(data_ new_data, linear_node<data_>* next = nullptr, linear_node<data_>* previous = nullptr) {
					this->this_data = new_data;
					this->next_node = next;
					this->previous_node = previous;
				}

				void set_next(linear_node<data_>* next) {
					this->next_node = next;
				}

				linear_node<data_>* get_next() const {
					return this->next_node;
				}

				void set_previous(linear_node<data_>* previous) {
					this->previous_node = previous;
				}

				linear_node<data_>* get_previous() const {
					return this->previous_node;
				}

		};

	}

	template <typename data_> class linear_linked_list {


		private:
			linear_node<data_> *front, *rear, *frame;
			unsigned long size, frame_index;

			void node_shifter(linear_node<data_>* this_node, unsigned long node_index, signed long by) {
				std::cout << "\t\tCall to node_shifter(" << "\"" << this_node->get_data() << "\", " << node_index << ", " << by << ")" << std::endl;
				signed long start_index = (signed long) node_index;
				while ((by != 0) && (this_node != nullptr) && (node_index != by)) {
					if (by > 0) {
						this_node = this_node->get_next();
						node_index = node_index + 1;
					}
					else {
						this_node = this_node->get_previous();
						node_index = node_index - 1;
					}
				}
				std::cout << "\t\t\tAt end of node_shifter, node_index is " << node_index << std::endl;
				std::cout << "\t\this_node->get_data() : \"" << this_node->get_data() << "\"" << std::endl;
			}

			void frame_shifter(signed long by) {
				while ((by != 0) && (this->frame != nullptr)) {
					this->frame = (by > 0) ? this->frame->get_next() : this->frame->get_previous();
					this->frame_index = (by > 0) ? this->frame_index + 1 : this->frame_index - 1;
					by = (by > 0) ? by - 1 : by + 1;
				}
			}


		public:

			linear_linked_list() {
				this->front = this->rear = this->frame = nullptr;
				this->size = 0;
				// std::cout << "Just called default constructor" << std::endl;
			}


			linear_linked_list(data_ new_data) {
				this->front = this->rear = this->frame = new linear_node<data_>(new_data);
				this->size = 1;
			}


			// Copy Constructor

			linear_linked_list(linear_linked_list<data_>& other_list) {
				if (this == &other_list) {
					return;
				}
				// this->reset();
				// this->front = this->frame = this->rear = nullptr;
				this->size = 0;
				// std::cout << "Copy constructor called. Original length is " << this->size << std::endl;
				// ~linear_linked_list();
				unsigned long index;
				for (index = 0; index < other_list.length(); index = index + 1) {
					this->push(other_list.peek(index));
				}
				// std::cout << "At end of copy constructor call. linear_linked_list has a length of " << this->size << std::endl;
				// std::cout << "At end of copy constructor call, data in this object is :" << std::endl;
				for (index = 0; index < this->size; index = index + 1) {
					std::cout << "\t" << this->peek(index) << std::endl;
				}
			}


			~linear_linked_list() {
				// std::cout << "Inside destructor" << std::endl;
				this->reset();
			}

			// Operator Overloading.

			// Assignment Operators
			// TODO CREATE ASSIGNMENT OPERATORS

			// Comparison operators

			bool operator==(linear_linked_list<data_>& other) {
				if (this == &other) {
					return true;
				}
				if (this->size == other.length()) {
					unsigned long index;
					for (index = 0; index < this->size; index = index + 1) {
						if (this->peek(index) != other.peek(index)) {
							return false;
						}
					}
					return true;
				}
				return false;
			}


			bool operator!=(linear_linked_list<data_>& other) {
				if (this == &other) {
					return false;
				}
				if (this->size != other.length()) {
					return true;
				}
				// the sizes are the same.
				unsigned long index;
				for (index = 0; index < this->size; index = index + 1) {
					if (this->peek(index) != other.peek(index)) {
						return true;
					}
				}
				return false;
			}


			data_& operator [](signed long index) {
				try {
					this->peek(index);
					// frame is now at index.
					return this->frame->get_data_ref();
				}
				catch (std::range_error except) {
					// std::cout << "Illegal index reference " << index << std::endl;
					// exit(EXIT_FAILURE);
					throw except;
				}

			}


			bool empty() const {
				return (this->size == 0);
			}

			unsigned long length() const {
				return this->size;
			}


			void push(data_ new_data, signed long index = -1) {
				unsigned long add_to;
				
				this->size = this->size + 1;
			}


			data_ peek(signed long index = -1) {
				// std::cout << "Raw peeking index " << index << std::endl;
				if (this->size == 0) {
					throw std::range_error(std::string("Cannot peek empty linked list"));
				}
				return this->frame->get_data();
			}


			void reset() {
				// std::cout << "Inside reset method" << std::endl;
				this->frame = this->front;
				while (this->frame != nullptr) {
					this->front = this->frame->get_next();
					// std::cout << "Deleting " << this->frame << std::endl << "\t->\"" << this->frame->get_data() << std::endl;
					delete this->frame;
					this->frame = this->front;
				}
				this->size = 0;
				// std::cout << "Finished reset call" << std::endl;
			}


	};

}