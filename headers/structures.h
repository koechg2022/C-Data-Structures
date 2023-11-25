#include <iostream>




// int counter = 1;

namespace data_structures {

	namespace {


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
				// std::cout << "\t\tCall to node_shifter(" << "\"" << this_node->get_data() << "\", " << node_index << ", " << by << ")" << // std::endl;
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
				// std::cout << "\t\t\tAt end of node_shifter, node_index is " << node_index << // std::endl;
				// std::cout << "\t\this_node->get_data() : \"" << this_node->get_data() << "\"" << // std::endl;
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
				// // std::cout << "Copy constructor called. Original length is " << this->size << // std::endl;
				// ~linear_linked_list();
				unsigned long index;
				for (index = 0; index < other_list.length(); index = index + 1) {
					this->push(other_list.peek(index));
				}
				// // std::cout << "At end of copy constructor call. linear_linked_list has a length of " << this->size << // std::endl;
				// // std::cout << "At end of copy constructor call, data in this object is :" << // std::endl;
				for (index = 0; index < this->size; index = index + 1) {
					// std::cout << "\t" << this->peek(index) << // std::endl;
				}
			}


			~linear_linked_list() {
				// // std::cout << "Inside destructor" << // std::endl;
				this->reset();
			}

			// Operator Overloading.

			// Assignment Operators
			// TODO CREATE ASSIGNMENT OPERATORS

			// Comparison operators

			bool operator==(linear_linked_list<data_>& other) {
				fprintf(stderr, "== operator not yet implemented\n");
				exit(EXIT_FAILURE);
			}




			bool operator!=(linear_linked_list<data_>& other) {
				fprintf(stderr, "!= operator not yet implemented\n");
				exit(EXIT_FAILURE);
			}




			bool operator<=(linear_linked_list<data_>& other) {
				fprintf(stderr, "<= operator not yet implemented\n");
				exit(EXIT_FAILURE);
			}




			data_& operator [](signed long index) {
				fprintf(stderr, "[] operator not yet implemented\n");
				exit(EXIT_FAILURE);
			}





			/**
			 * @brief Check if the current linked list is empty or not.
			 * 
			 * @returns `(bool)` : true if the linked list is empty, false otherwise.
			*/
			bool empty() const {
				return (this->size == 0);
			}




			/**
			 * @brief Get the size of the linked list.
			 * 
			 * @returns `(unsigned long)` : The length of the linked list.
			*/
			unsigned long length() const {
				return this->size;
			}





			/**
			 * @brief Empties out the linked list and frees up memory.
			 * 
			 * @returns void.
			*/
			void reset() {
				// // std::cout << "Inside reset method" << // std::endl;
				this->frame = this->front;
				while (this->frame != nullptr) {
					this->front = this->frame->get_next();
					delete this->frame;
					this->frame = this->front;
				}
				this->size = 0;
			}




			void push(data_ new_data, signed long index = -1) {
				unsigned long add_index = (index < 0) ? ((unsigned long) useful_functions::absolute<signed long>(index)) + 1 - this->size : (unsigned long) useful_functions::absolute<signed long>(index);
				if (add_index > this->size) {
					throw std::range_error("Cannot push data to negative index whose absolute value converts to a larger value than the size of the list");
				}
				
				linear_node<data_>* new_node = new linear_node<data_>(new_data);
				
				if (this->size == 0) {
					this->front = this->rear = this->frame = new_node;
				}

				else if (this->size == 1) {

					if (add_index == 0) {
						this->front->set_previous(new_node);
						this->front->get_previous()->set_next(this->front);
						this->front = this->front->get_previous();
						this->frame = this->front;
					}

					else {
						// index is 1
						this->rear->set_next(new_node);
						this->rear->get_next()->set_previous(this->rear);
						this->rear = this->rear->get_next();
						this->frame = this->rear;
					}
				}

				else {
					if (add_index == 0) {
						this->front->set_previous(new_node);
						this->front->get_previous()->set_next(this->front);
						this->front = this->front->get_previous();
						this->frame = this->front;
					}
					else if (add_index == this->size) {
						this->rear->set_next(new_node);
						this->rear->get_next()->set_previous(this->rear);
						this->rear = this->rear->get_next();
						this->frame = this->rear;
					}
					else {
						// this is where some extra work comes into play.
						
					}
				}
				this->size = this->size + 1;
			}




	};

}